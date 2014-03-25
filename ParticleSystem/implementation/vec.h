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

#ifndef ParticleSystem_vector_h
#define ParticleSystem_vector_h

template <class T>
class vec3
{
public:
    T x,y,z;

    vec3() {}
    vec3(T x_, T y_, T z_):x(x_), y(y_), z(z_) {}
    vec3(const vec3<T>& v):x(v.x),y(v.y),z(v.z) {}
    
    template<class C>
    vec3<T>&    operator=(const vec3<C>& c)
    {
        x = c.x;
        y = c.y;
        z = c.z;
        
        return *this;
    }
    
    template <class C>
    vec3<T>&    operator+=(const vec3<C>& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        
        return *this;
    }

    vec3<T>&    operator*=(T c)
    {
        x *= c;
        y *= c;
        z *= c;
        
        return *this;
    }

    template <class C>
    vec3<T>&    operator*=(const vec3<C>& c)
    {
        x *= c.x;
        y *= c.y;
        z *= c.z;
        
        return *this;
    }

    void    set(T _x, T _y, T _z)
    {
        x = _x; y = _y; z = _z;
    }
    
    static  vec3<T> zero()
    {
        return vec3<T>(0,0,0);
    }
    
    template <class A, class B>
    friend vec3<A>  operator+(const vec3<A>& a,const vec3<B>& b);

    template <class M>
    friend vec3<M>    operator*(const vec3<M>& a,M c);

    template <class A, class C>
    friend vec3<A>    operator*(const vec3<A>& a, const vec3<C>& c);
};

template <class A, class B>
vec3<A>  operator+(const vec3<A>& a,const vec3<B>& b)
{
    vec3<A> c = a;
    c += b;
    return c;
}

template <class T>
vec3<T> operator*(const vec3<T>& a,T c)
{
    vec3<T> b = a;
    b *= c;
    
    return b;
}

template <class A, class C>
vec3<A>    operator*(const vec3<A>& a, const vec3<C>& c)
{
    vec3<A> b = a;
    b *= c;
    
    return b;
}

template <class T>
class vec4
{
public:
    T x,y,z,w;
    
    vec4() {}
    vec4(T x_, T y_, T z_, T w_):x(x_), y(y_), z(z_), w(w_) {}
    vec4(const vec4<T>& v):x(v.x),y(v.y),z(v.z),w(v.w) {}
    
    static  vec4<T> zero()
    {
        return vec4<T>(0,0,0,0);
    }
};

template <class T>
struct vec3range
{
    vec3<T> vecMin;
    vec3<T> vecMax;
};

template <class T>
struct vec4range
{
    vec4<T> vecMin;
    vec4<T> vecMax;
};

typedef vec3range<float> vec3rangef;
typedef vec4range<float> vec4rangef;
typedef vec3<float> vec3f;
typedef vec4<float> vec4f;
typedef vec3<int> vec3i;

#endif
