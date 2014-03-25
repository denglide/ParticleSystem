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

#include "Particle.h"
#include <algorithm>

Particle::Particle(vertexData_t* v, const EmitterState& s):data(v), state(s)
{
    
}

Particle::~Particle()
{
    
}

bool Particle::update(float dt)
{
    data->position += vel*dt;
    vel += state.gravity*dt;
    life -= dt;

    data->color = vec4f(data->color.x + colorVelocity.x*dt,
                        data->color.y + colorVelocity.y*dt,
                        data->color.z + colorVelocity.z*dt,
                        data->color.w + colorVelocity.w*dt);

    return isAlive();
}

bool    Particle::isAlive() const
{
    return life > 0;
}

void    Particle::swap(Particle* p)
{
    std::swap(data, p->data);
    std::swap(*data, *p->data);
}