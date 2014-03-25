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

#ifndef ParticleSystem_mutils_h
#define ParticleSystem_mutils_h

#include "vec.h"
#include "math.h"
#include <stdlib.h>

inline float   rndFloat()
{
    return ((float)rand()/INT_MAX);
}

inline float   rndFloatInRange(float a, float b)
{
    float r = rndFloat();
    return a*(1-r) + b*r;
}

inline vec3f   rndVec3InRange(const vec3rangef& range)
{
    float r1 = rndFloat();
    float r2 = rndFloat();
    float r3 = rndFloat();
    
    return vec3f(range.vecMin.x*(1-r1) + range.vecMax.x*r1,
                 range.vecMin.y*(1-r2) + range.vecMax.y*r2,
                 range.vecMin.z*(1-r3) + range.vecMax.z*r3);
}

inline vec4f   rndVec4InRange(const vec4rangef& range)
{
    float r1 = rndFloat();
    float r2 = rndFloat();
    float r3 = rndFloat();
    float r4 = rndFloat();
    
    return vec4f(range.vecMin.x*(1-r1) + range.vecMax.x*r1,
                 range.vecMin.y*(1-r2) + range.vecMax.y*r2,
                 range.vecMin.z*(1-r3) + range.vecMax.z*r3,
                 range.vecMin.w*(1-r4) + range.vecMax.w*r4);
}


#endif
