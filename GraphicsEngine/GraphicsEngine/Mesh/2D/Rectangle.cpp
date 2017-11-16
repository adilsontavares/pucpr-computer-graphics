//
//  Rectangle.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 06/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(GLfloat width, GLfloat height)
{
    this->width = width;
    this->height = height;
    
    reset();
}

void Rectangle::generate()
{
    Mesh mesh;
    
    const auto w2 = width * 0.5;
    const auto h2 = height * 0.5;
    
    mesh.vertices.push_back(Vector3(-w2, -h2, 0));
    mesh.vertices.push_back(Vector3( w2, -h2, 0));
    mesh.vertices.push_back(Vector3( w2,  h2, 0));
    mesh.vertices.push_back(Vector3(-w2,  h2, 0));
    
    mesh.faces.push_back(0);
    mesh.faces.push_back(1);
    mesh.faces.push_back(2);
    mesh.faces.push_back(2);
    mesh.faces.push_back(3);
    mesh.faces.push_back(0);
    
    addMesh(mesh);
}

void Rectangle::setWidth(GLfloat width)
{
    this->width = width;
    reset();
}

void Rectangle::setHeight(GLfloat height)
{
    this->height = height;
    reset();
}

GLfloat Rectangle::getWidth()
{
    return width;
}

GLfloat Rectangle::getHeight()
{
    return height;
}
