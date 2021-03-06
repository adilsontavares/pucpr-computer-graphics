//
//  Cube.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Cube.hpp"

Cube::Cube(GLfloat size) : Box(size, size, size)
{
}

void Cube::setSize(GLfloat size)
{
    this->size = size;
    
    width = size;
    height = size;
    depth = size;
    
    reset();
}

GLfloat Cube::getSize()
{
    return size;
}

Cube *Cube::create(DisplayFileObject *config)
{
    config->assertFloat("size");
    return new Cube(config->getFloat("size"));
}
