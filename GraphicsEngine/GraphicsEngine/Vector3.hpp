//
//  Vector3.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <stdio.h>
#include <GL/glew.h>

class Vector3
{
public:
    
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
    Vector3();
    Vector3(GLfloat v);
    Vector3(GLfloat x, GLfloat y, GLfloat z);
    
    friend Vector3 operator + (const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }
    friend Vector3 operator - (const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }
    friend Vector3 operator * (const Vector3& a, GLfloat m) { return Vector3(a.x * m, a.y * m, a.z * m); }
    
    GLfloat magnitude();
    GLuint bytes();
};

#endif /* Vector3_hpp */
