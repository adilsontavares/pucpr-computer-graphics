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
    Mesh mesh;
    mesh.setDrawMode(GL_TRIANGLE_STRIP);
    
    for (GLuint lin = 1; lin <= divisions; ++lin)
    {
        auto angle1 = 2.0 * M_PI * ((lin - 1) / GLfloat(divisions));
        auto angle2 = 2.0 * M_PI * (lin / GLfloat(divisions));
        
        auto base1 = sin(angle1) * radius;
        auto base2 = sin(angle2) * radius;
        
        auto rad1 = sin(angle1 + M_PI_2) * radius;
        auto rad2 = sin(angle2 + M_PI_2) * radius;
        
        for (GLuint col = 0; col <= divisions; ++col)
        {
            auto angle = 2 * M_PI * (col / GLfloat(divisions));
            auto x = cos(angle);
            auto y = sin(angle);
            
            mesh.vertices.push_back(Vector3(x * rad1, base1, y * rad1));
            mesh.vertices.push_back(Vector3(x * rad2, base2, y * rad2));
            
            mesh.colors.push_back(Color::green());
            mesh.colors.push_back(Color::red());
        }
    }
    
    addMesh(mesh);
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

