//
//  Program.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Program.hpp"
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

Program::Program(Shader *vertex, Shader *fragment)
{
    this->vertex = vertex;
    this->fragment = fragment;
    
    id = glCreateProgram();
    glAttachShader(id, vertex->getId());
    glAttachShader(id, fragment->getId());
    glLinkProgram(id);
}

void Program::use()
{
    glUseProgram(id);
}

Program *Program::simple()
{
    auto vertex = new VertexShader("assets/Simple.vs");
    auto fragment = new FragmentShader("assets/Simple.fs");
    auto program = new Program(vertex, fragment);
    
    return program;
}

GLuint Program::getId()
{
    return id;
}
