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

#ifndef __ParticleSystem__Particle__
#define __ParticleSystem__Particle__

#include "EmitterState.h"

struct vertexData_t
{
    vec3f   position;
    vec4f   color;
};

class ParticleEmitter;

class Particle
{
public:

    Particle(vertexData_t* v, const EmitterState& state);
    virtual ~Particle();
    virtual bool update(float dt);
    bool    isAlive() const;

    static  float   stride()  { return sizeof(Particle); }
    
    friend class ParticleEmitter;

    void    swap(Particle* p);
    
private:
    
    const EmitterState& state;
    vertexData_t*    data;
    
    vec3f   vel;
    vec4f   colorVelocity;
    
    float   life;
    float   size;
};

#endif /* defined(__ParticleSystem__Particle__) */
