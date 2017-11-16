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

void Cylinder::generate()
{
    Mesh mesh;
    
    const auto h2 = height * 0.5;
    
    mesh.vertices.push_back(Vector3(0, h2, 0));
    mesh.vertices.push_back(Vector3(0, -h2, 0));
    
    mesh.colors.push_back(Color::red());
    mesh.colors.push_back(Color::green());
    
    for (GLuint i = 0; i < divisions; ++i)
    {
        auto angle = 2 * M_PI * (i / GLfloat(divisions));
        auto x = cos(angle) * radius;
        auto z = sin(angle) * radius;
        
        mesh.vertices.push_back(Vector3(x, h2, z));
        mesh.vertices.push_back(Vector3(x, -h2, z));
        
        mesh.colors.push_back(Color(x * 0.5 + 0.5, 1, z * 0.5 + 0.5));
        mesh.colors.push_back(Color(x * 0.5 + 0.5, 0, z * 0.5 + 0.5));
    }
    
    for (GLuint i = 2; i < mesh.vertices.size() - 2; i += 2)
    {
        mesh.faces.push_back(i);
        mesh.faces.push_back(i + 1);
        mesh.faces.push_back(i + 2);
        
        mesh.faces.push_back(i + 1);
        mesh.faces.push_back(i + 2);
        mesh.faces.push_back(i + 3);
        
        mesh.faces.push_back(i + 1);
        mesh.faces.push_back(i + 3);
        mesh.faces.push_back(1);
        
        mesh.faces.push_back(i);
        mesh.faces.push_back(i + 2);
        mesh.faces.push_back(0);
    }
    
    const auto lastIndex = GLuint(mesh.vertices.size() - 1);
    
    mesh.faces.push_back(0);
    mesh.faces.push_back(2);
    mesh.faces.push_back(lastIndex - 1);
    
    mesh.faces.push_back(2);
    mesh.faces.push_back(lastIndex - 1);
    mesh.faces.push_back(lastIndex - 0);
    
    mesh.faces.push_back(2);
    mesh.faces.push_back(3);
    mesh.faces.push_back(lastIndex - 0);
    
    mesh.faces.push_back(lastIndex);
    mesh.faces.push_back(3);
    mesh.faces.push_back(1);
    
    addMesh(mesh);
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
