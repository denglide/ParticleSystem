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

#ifndef __ParticleSystem__ParticleEmitter__
#define __ParticleSystem__ParticleEmitter__

#include "Particle.h"
#include <vector>
#include "mutils.h"
#include "EmitterState.h"
#include "ParticleRenderer.h"

struct EmitterConfig
{
    float   emissionRate;
    vec3f   position;
    vec3f   lifeRange;
    
    float   lifeTime;
    
    EmitterState    state;
    
    vec3rangef velocityRange;
    vec4rangef colorRange;
    vec4rangef colorVelocityRange;
};

class ParticleEmitter
{
public:
    ParticleEmitter();
    virtual ~ParticleEmitter();
    
    virtual bool    update(float dt);
    virtual void    render(ParticleRenderer* renderer);

    void    reset();
    void    init(int maxParticles, const EmitterConfig& config);

    EmitterConfig&   GetConfig() { return config_; }
    void    SetConfig(const EmitterConfig& config) {config_ = config;}
    
protected:

    typedef std::vector<Particle*> particles_t;
    typedef std::vector<vertexData_t> vertices_t;
    
    void    clean();
    virtual Particle*   makeParticle(int idx);
    virtual Particle*   prepareParticle(Particle*, float dt);
    particles_t particles_;
    vertices_t  vertices_;
    
    int maxParticles_;
    int currentCount_;
    float   genRemainder_;
    
    EmitterConfig    config_;
    
    float   runTime_;
    
    void    check();
};

#endif /* defined(__ParticleSystem__ParticleEmitter__) */
