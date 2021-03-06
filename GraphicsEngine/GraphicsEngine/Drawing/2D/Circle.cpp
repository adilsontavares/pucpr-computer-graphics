//
//  Circle.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 06/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Circle.hpp"
#include <cmath>

Circle::Circle(GLfloat radius, GLuint divisions)
{
    this->radius = radius;
    this->divisions = divisions;
    
    reset();
}

void Circle::setRadius(GLfloat radius)
{
    this->radius = radius;
    reset();
}

void Circle::setDivisions(GLuint divisions)
{
    this->divisions = divisions;
    reset();
}

GLfloat Circle::getRadius()
{
    return radius;
}

GLuint Circle::getDivisions()
{
    return divisions;
}

void Circle::generate()
{
    Mesh mesh;
    
    mesh.vertices.push_back(Vector3(0, 0, 0));
    mesh.colors.push_back(Color::red());
    
    for (GLuint i = 0; i < divisions; ++i)
    {
        GLfloat angle = (GLfloat(i) / divisions) * 2 * M_PI;
        mesh.vertices.push_back(Vector3(cos(angle) * radius, sin(angle) * radius, 0));
        
        mesh.colors.push_back(Color(cos(angle) * 0.5 + 0.5, 0, sin(angle) * 0.5 + 0.5));
    }
    
    for (GLuint i = 1; i < mesh.vertices.size() - 1; ++i)
    {
        mesh.faces.push_back(i);
        mesh.faces.push_back(i + 1);
        mesh.faces.push_back(0);
    }
    
    mesh.faces.push_back(GLuint(mesh.vertices.size()) - 1);
    mesh.faces.push_back(1);
    mesh.faces.push_back(0);
    
    addMesh(mesh);
}
