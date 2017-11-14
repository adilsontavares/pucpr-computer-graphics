//
//  Color.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Color.hpp"
#include <iostream>
#include <sstream>
#include <cassert>

Color::Color()
{
    r = g = b = a = 1;
}

Color::Color(const char *hex)
{
    auto str = hex[0] == '#' ? (hex + 1) : hex;
    auto length = strlen(str);
    assert(length == 6 || length == 8);
    
    unsigned int x;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> x;
    
    GLubyte r, g, b, a = 255;
    
    std::cout << "NUM: " << x << std::endl;
    
    if (length == 6)
    {
        r = (x & 0xFF0000) >> 16;
        g = (x & 0xFF00) >> 8;
        b = (x & 0xFF);
    }
    else
    {
        r = (x & 0xFF000000) >> 24;
        g = (x & 0xFF0000) >> 16;
        b = (x & 0x00FF) >> 8;
        a = (x & 0xFF);
    }
    
    this->r = r / 255.0;
    this->g = g / 255.0;
    this->b = b / 255.0;
    this->a = a / 255.0;
}

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

Color Color::withAlpha(GLfloat a)
{
    return Color(r, g, b, a);
}

GLuint Color::bytes()
{
    return sizeof(r) * 4;
}
