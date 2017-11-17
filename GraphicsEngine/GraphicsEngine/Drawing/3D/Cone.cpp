//
//  Cone.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Cone.hpp"
#include <cmath>
#include <cassert>

Cone::Cone(GLfloat radius, GLfloat height, GLuint divisions) : Primitive()
{
    this->radius = radius;
    this->height = height;
    this->divisions = divisions;
    assert(divisions >= 3);
    
    reset();
}

void Cone::generate()
{
    Mesh mesh;
    
    auto top = Vector3(0, height * 0.5, 0);
    auto base = Vector3(0, -height * 0.5, 0);
    
    mesh.vertices.push_back(top);
    mesh.vertices.push_back(base);
    
    mesh.colors.push_back(Color::green());
    mesh.colors.push_back(Color::blue());
    
    for (int i = 0; i < divisions; ++i)
    {
        auto angle = (2 * M_PI) * ((GLfloat)i / divisions);
        auto cosine = cos(angle);
        auto sine = sin(angle);
        
        auto vertice = base + Vector3(cosine * radius, 0, sine * radius);
        mesh.vertices.push_back(vertice);
        
        mesh.colors.push_back(Color(sine * 0.5 + 0.5, 0, 0));
    }
    
    for (GLuint i = 1; i < divisions; ++i)
    {
        mesh.faces.push_back(0);
        mesh.faces.push_back(i + 1);
        mesh.faces.push_back(i + 2);
        
        mesh.faces.push_back(i + 2);
        mesh.faces.push_back(i + 1);
        mesh.faces.push_back(1);
    }
    
    mesh.faces.push_back(0);
    mesh.faces.push_back(2);
    mesh.faces.push_back(GLuint(mesh.vertices.size() - 1));
    
    mesh.faces.push_back(GLuint(mesh.vertices.size() - 1));
    mesh.faces.push_back(2);
    mesh.faces.push_back(1);
    
    addMesh(mesh);
}

void Cone::setDivisions(GLuint divisions)
{
    this->divisions = divisions;
    assert(divisions >= 3);
    
    reset();
}

void Cone::setRadius(GLfloat radius)
{
    this->radius = radius;
    reset();
}

void Cone::setHeight(GLfloat height)
{
    this->height = height;
    reset();
}

GLuint Cone::getDivisions()
{
    return divisions;
}

GLfloat Cone::getRadius()
{
    return radius;
}

GLfloat Cone::getHeight()
{
    return height;
}
