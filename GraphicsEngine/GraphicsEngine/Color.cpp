//
//  Color.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Color.hpp"

Color::Color(GLfloat r, GLfloat g, GLfloat b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 1;
}

Color::Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color Color::red()
{
    return Color(1, 0, 0);
}

Color Color::green()
{
    return Color(0, 1, 0);
}

Color Color::blue()
{
    return Color(0, 0, 1);
}

Color Color::black()
{
    return Color(0, 0, 0);
}

Color Color::white()
{
    return Color(1, 1, 1);
}

Color Color::gray()
{
    return Color(0.5, 0.5, 0.5);
}
