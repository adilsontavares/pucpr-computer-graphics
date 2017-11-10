//
//  Vector3.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Vector3.hpp"
#include "Math.hpp"

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

Vector3 Vector3::deg2rad()
{
    return Vector3(DEG2RAD(x), DEG2RAD(y), DEG2RAD(z));
}

Vector3 Vector3::rad2deg()
{
    return Vector3(RAD2DEG(x), RAD2DEG(y), RAD2DEG(z));
}

Vector3 Vector3::up()
{
    return Vector3(0, 1, 0);
}

Vector3 Vector3::right()
{
    return Vector3(1, 0, 0);
}

Vector3 Vector3::forward()
{
    return Vector3(0, 0, 1);
}
