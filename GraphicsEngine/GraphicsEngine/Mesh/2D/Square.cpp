//
//  Square.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 06/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Square.hpp"

Square::Square(GLfloat size) : Rectangle(size, size)
{
    setSize(size);
}

void Square::setSize(GLfloat size)
{
    this->width = size;
    this->height = size;
    reset();
}

GLfloat Square::getSize()
{
    return width;
}
