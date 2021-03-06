//
//  Box.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Box.hpp"
#include <cassert>

Box* Box::create(DisplayFileObject *config)
{
    config->assertFloat("width");
    config->assertFloat("height");
    config->assertFloat("depth");
    
    GLfloat width = config->getFloat("width");
    GLfloat height = config->getFloat("height");
    GLfloat depth = config->getFloat("depth");
    
    return new Box(width, height, depth);
}

Box::Box(GLfloat width, GLfloat height, GLfloat depth) : Primitive()
{
    this->width = width;
    this->height = height;
    this->depth = depth;
    
    reset();
}

void Box::generate()
{
    Mesh mesh;
    
    auto w2 = width * 0.5;
    auto h2 = height * 0.5;
    auto d2 = depth * 0.5;
    
    Vector3 vertices[] = {
        
        // front
        Vector3(-w2,  h2, -d2),
        Vector3( w2,  h2, -d2),
        Vector3( w2, -h2, -d2),
        Vector3(-w2, -h2, -d2),
        
        // back
        Vector3(-w2,  h2,  d2),
        Vector3( w2,  h2,  d2),
        Vector3( w2, -h2,  d2),
        Vector3(-w2, -h2,  d2),
    };
    
    GLuint faces[] = {
        
        // front
        0, 1, 3,
        1, 2, 3,

        // back
        4, 6, 5,
        4, 7, 6,

        // right
        1, 5, 2,
        5, 6, 2,

        // left
        0, 7, 4,
        0, 3, 7,

        // top
        0, 4, 5,
        0, 5, 1,

        // bottom
        2, 3, 7,
        2, 7, 6
    };
    
    Color colors[] = {
        
        Color::red(),
        Color::green(),
        Color::green(),
        Color::red(),
        
        Color::blue(),
        Color::green(),
        Color::green(),
        Color::blue()
    };
    
    mesh.setVertices(vertices, 8);
    mesh.setColors(colors, 8);
    mesh.setFaces(faces, 36);
    
    addMesh(mesh);
}

void Box::setWidth(GLfloat width)
{
    this->width = width;
    reset();
}

void Box::setHeight(GLfloat height)
{
    this->height = height;
    reset();
}

void Box::setDepth(GLfloat depth)
{
    this->depth = depth;
    reset();
}
