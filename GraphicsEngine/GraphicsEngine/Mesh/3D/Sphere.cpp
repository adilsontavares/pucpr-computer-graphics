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
    
    reset();
}

Sphere *Sphere::create(DisplayFileObject *config)
{
    config->assertFloat("radius");
    
    GLfloat radius = config->getFloat("radius");
    GLuint divisions = 8;
    
    if (config->hasProperty("divisions"))
        divisions = config->getInt("divisions");
    
    return new Sphere(radius, divisions);
}

void Sphere::generate()
{
    
}

void Sphere::setDivisions(GLuint divisions)
{
    this->divisions = divisions;
    assert(divisions >= 3);
    
    reset();
}

void Sphere::setRadius(GLfloat radius)
{
    this->radius = radius;
    reset();
}

GLuint Sphere::getDivisions()
{
    return divisions;
}

GLfloat Sphere::getRadius()
{
    return radius;
}

