//
//  Cylinder.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Cylinder.hpp"
#include <cmath>
#include "Color.hpp"

Cylinder::Cylinder(GLfloat radius, GLfloat height, GLuint divisions) : Primitive()
{
    this->radius = radius;
    this->height = height;
    this->divisions = divisions;
    assert(divisions >= 3);
    
    resetMesh();
}

void Cylinder::resetMesh()
{
    vertices.clear();
    colors.clear();
    faces.clear();
    
    const auto h2 = height * 0.5;
    
    vertices.push_back(Vector3(0, h2, 0));
    vertices.push_back(Vector3(0, -h2, 0));
    
    colors.push_back(Color::red());
    colors.push_back(Color::green());
    
    for (GLuint i = 0; i < divisions; ++i)
    {
        auto angle = 2 * M_PI * (i / GLfloat(divisions));
        auto x = cos(angle) * radius;
        auto z = sin(angle) * radius;
        
        vertices.push_back(Vector3(x, h2, z));
        vertices.push_back(Vector3(x, -h2, z));
        
        colors.push_back(Color(x * 0.5 + 0.5, 1, z * 0.5 + 0.5));
        colors.push_back(Color(x * 0.5 + 0.5, 0, z * 0.5 + 0.5));
    }
    
    for (GLuint i = 2; i < vertices.size() - 2; i += 2)
    {
        faces.push_back(i);
        faces.push_back(i + 1);
        faces.push_back(i + 2);
        
        faces.push_back(i + 1);
        faces.push_back(i + 2);
        faces.push_back(i + 3);
        
        faces.push_back(i + 1);
        faces.push_back(i + 3);
        faces.push_back(1);
        
        faces.push_back(i);
        faces.push_back(i + 2);
        faces.push_back(0);
    }
    
    const auto lastIndex = GLuint(vertices.size() - 1);
    
    faces.push_back(0);
    faces.push_back(2);
    faces.push_back(lastIndex - 1);
    
    faces.push_back(2);
    faces.push_back(lastIndex - 1);
    faces.push_back(lastIndex - 0);
    
    faces.push_back(2);
    faces.push_back(3);
    faces.push_back(lastIndex - 0);
    
    faces.push_back(lastIndex);
    faces.push_back(3);
    faces.push_back(1);
}

void Cylinder::setRadius(GLfloat radius)
{
    this->radius = radius;
    resetMesh();
}

void Cylinder::setHeight(GLfloat height)
{
    this->height = height;
    resetMesh();
}

void Cylinder::setDivisions(GLuint divisions)
{
    this->divisions = divisions;
    assert(divisions >= 3);
    
    resetMesh();
}

GLfloat Cylinder::getRadius()
{
    return radius;
}

GLfloat Cylinder::getHeight()
{
    return height;
}

GLuint Cylinder::getDivisions()
{
    return divisions;
}
