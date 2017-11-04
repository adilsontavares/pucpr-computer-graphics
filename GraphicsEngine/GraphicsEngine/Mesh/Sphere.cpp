//
//  Sphere.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Sphere.hpp"
#include <cmath>
#include <cassert>

Sphere::Sphere(GLfloat radius, GLuint divisions) : Primitive()
{
    this->radius = radius;
    this->divisions = divisions;
    assert(divisions >= 3);
    
    resetMesh();
}

void Sphere::resetMesh()
{
    vertices.clear();
    colors.clear();
    faces.clear();
    
    // CREATE SPHERE HERE!
}

void Sphere::setDivisions(GLuint divisions)
{
    this->divisions = divisions;
    assert(divisions >= 3);
    
    resetMesh();
}

void Sphere::setRadius(GLfloat radius)
{
    this->radius = radius;
    resetMesh();
}

GLuint Sphere::getDivisions()
{
    return divisions;
}

GLfloat Sphere::getRadius()
{
    return radius;
}

