//
//  Triangle.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 07/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(GLfloat radius)
{
    this->radius = radius;
    reset();
}

void Triangle::setRadius(GLfloat radius)
{
    this->radius = radius;
    reset();
}

GLfloat Triangle::getRadius()
{
    return radius;
}

void Triangle::generate()
{
    Mesh mesh;
    
    const GLuint count = 3;
    for (GLuint i = 0; i < count; ++i)
    {
        GLfloat angle = (i / GLfloat(count)) * 2 * M_PI + M_PI_2;
        
        vertices.push_back(Vector3(cos(angle) * radius, sin(angle) * radius, 0));
        faces.push_back(i);
    }
    
    colors.push_back(Color::red());
    colors.push_back(Color::green());
    colors.push_back(Color::blue());
    
    addMesh(mesh);
}
