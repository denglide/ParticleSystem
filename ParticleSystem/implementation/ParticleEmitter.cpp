/*
 The MIT License (MIT)
 
 Copyright (c) 2014 Denis Gladkov
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include "ParticleEmitter.h"
#include <algorithm>
#include <functional>
#include <iostream>

ParticleEmitter::ParticleEmitter():genRemainder_(0)
{
}

ParticleEmitter::~ParticleEmitter()
{
    
}

void    ParticleEmitter::clean()
{
    for(int i = 0; i < particles_.size(); i++)
        delete particles_[i];
    
    particles_.clear();
}

void    ParticleEmitter::init(int maxParticles, const EmitterConfig& config)
{
    srand(clock());
    maxParticles_ = maxParticles;
    currentCount_ = 0;
    genRemainder_ = 0;
    config_ = config;
    particles_.resize(maxParticles_);
    vertices_.resize(maxParticles_);
    
    for(int i = 0; i < particles_.size(); i++)
        particles_[i] = makeParticle(i);
    
    runTime_ = config.lifeTime;
}

void    ParticleEmitter::reset()
{
    clean();
    init(maxParticles_, config_);
}
//glBindAttribLocation
bool    ParticleEmitter::update(float dt)
{
    bool emit = (config_.lifeTime <= 0 || runTime_ > 0);
    float   gen = (emit)?config_.emissionRate*dt + genRemainder_:0;
    int pGen = gen;
    genRemainder_ = gen - pGen;
    
    // update current particles
    
    for(int i = 0; i < currentCount_;)
    {
        if(!particles_[i]->update(dt))
        {
            if(i != currentCount_-1)
            {
                particles_[i]->swap(particles_[currentCount_-1]);
                std::swap(particles_[i], particles_[currentCount_-1]);
            }
            currentCount_--;
        }else
            i++;
    }
    
    // generate pGen particles
    int newEnd = std::min(pGen+currentCount_, maxParticles_);
    
    for(;currentCount_ < newEnd; currentCount_++)
        prepareParticle(particles_[currentCount_], dt);

    runTime_ -= dt;
    return config_.lifeTime <= 0 || runTime_ > 0;
    
    
//    check();
}

void    ParticleEmitter::check()
{
    for(int i = 0; i < currentCount_; i++)
        if(particles_[i]->data->position.x == 0 && particles_[i]->data->position.y == 0)
            std::cout<<"ERROR: "<<i<<"\n";
    
    std::cout<<"DONE: "<<currentCount_<<"\n";
}

void    ParticleEmitter::render(ParticleRenderer* renderer)
{
    renderer->render(&vertices_[0], currentCount_);
}

Particle*   ParticleEmitter::makeParticle(int idx)
{
    return new Particle(&vertices_[idx], config_.state);
}

Particle*   ParticleEmitter::prepareParticle(Particle* p, float dt)
{
    p->data->position = config_.position;
    p->vel = rndVec3InRange(config_.velocityRange);
    p->size = 0.1f;
    p->life = rndFloatInRange(config_.lifeRange.x, config_.lifeRange.y);
    p->data->color = rndVec4InRange(config_.colorRange);
    p->colorVelocity = rndVec4InRange(config_.colorVelocityRange);

    p->update(dt);
    
    return p;
}
