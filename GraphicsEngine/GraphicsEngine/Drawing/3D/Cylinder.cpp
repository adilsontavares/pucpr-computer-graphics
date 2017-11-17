//
//  Cylinder.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Cylinder.hpp"
#include <cmath>
#include <cassert>
#include "Color.hpp"

Cylinder::Cylinder(GLfloat radius, GLfloat height, GLuint divisions) : Primitive()
{
    this->radius = radius;
    this->height = height;
    this->divisions = divisions;
    assert(divisions >= 3);
    
    reset();
}

Cylinder *Cylinder::create(DisplayFileObject *config)
{
    config->assertFloat("radius");
    config->assertFloat("height");
    
    GLfloat radius = config->getFloat("radius");
    GLfloat height = config->getFloat("height");
    
    GLuint divisions = 8;
    
    if (config->hasProperty("divisions"))
        divisions = config->getFloat("divisions");
    
    return new Cylinder(radius, height, divisions);
}

void Cylinder::generateTop()
{
    Mesh mesh;
    mesh.setDrawMode(GL_TRIANGLE_FAN);
    
    auto base = Vector3(0, height * 0.5, 0);
    
    mesh.vertices.push_back(base);
    
    for (GLuint i = 0; i <= divisions; ++i)
    {
        auto angle = 2 * M_PI * (1 - (i / GLfloat(divisions)));
        auto x = cos(angle) * radius;
        auto y = sin(angle) * radius;
        
        mesh.vertices.push_back(base + Vector3(x, 0, y));
    }
    
    addMesh(mesh);
}

void Cylinder::generateBottom()
{
    Mesh mesh;
    mesh.setDrawMode(GL_TRIANGLE_FAN);
    
    auto base = Vector3(0, -height * 0.5, 0);
    
    mesh.vertices.push_back(base);
    
    for (GLuint i = 0; i <= divisions; ++i)
    {
        auto angle = 2 * M_PI * (i / GLfloat(divisions));
        auto x = cos(angle) * radius;
        auto y = sin(angle) * radius;
        
        mesh.vertices.push_back(base + Vector3(x, 0, y));
    }
    
    addMesh(mesh);
}

void Cylinder::generateBody()
{
    Mesh mesh;
    mesh.setDrawMode(GL_TRIANGLE_STRIP);
    
    auto top = Vector3(0, height * 0.5, 0);
    auto bottom = Vector3(0, -height * 0.5, 0);
    
    for (GLuint i = 0; i <= divisions; ++i)
    {
        auto angle = 2 * M_PI * (1 - (i / GLfloat(divisions)));
        auto x = cos(angle) * radius;
        auto y = sin(angle) * radius;
        auto offset = Vector3(x, 0, y);
        
        mesh.vertices.push_back(top + offset);
        mesh.vertices.push_back(bottom + offset);
    }
    
    addMesh(mesh);
}

void Cylinder::generate()
{
    generateTop();
    generateBottom();
    generateBody();
}

void Cylinder::setRadius(GLfloat radius)
{
    this->radius = radius;
    reset();
}

void Cylinder::setHeight(GLfloat height)
{
    this->height = height;
    reset();
}

void Cylinder::setDivisions(GLuint divisions)
{
    this->divisions = divisions;
    assert(divisions >= 3);
    
    reset();
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
