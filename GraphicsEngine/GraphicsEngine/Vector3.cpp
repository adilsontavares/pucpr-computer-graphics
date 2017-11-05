//
//  Vector3.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Vector3.hpp"

Vector3::Vector3()
{
    x = y = z = 0;
}

Vector3::Vector3(GLfloat v)
{
    x = y = z = v;
}

Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

GLfloat Vector3::magnitude()
{
    return x * x + y * y + z * z;
}

GLuint Vector3::bytes()
{
    return sizeof(x) * 3;
}
