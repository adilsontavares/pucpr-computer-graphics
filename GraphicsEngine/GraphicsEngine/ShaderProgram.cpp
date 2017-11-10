//
//  ShaderProgram.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "ShaderProgram.hpp"
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

ShaderProgram::ShaderProgram(VertexShader *vertex, FragmentShader *fragment)
{
    this->vertex = vertex;
    this->fragment = fragment;
    
    id = glCreateProgram();
    glAttachShader(id, vertex->getId());
    glAttachShader(id, fragment->getId());
    glLinkProgram(id);
}

void ShaderProgram::begin()
{
    glUseProgram(id);
    
    auto it = arguments.begin();
    while (it != arguments.end())
    {
        auto arg = (*it).second;

        glEnableVertexAttribArray(arg->location);
        arg->set();

        it++;
    }
}

void ShaderProgram::end()
{
    auto it = arguments.begin();
    while (it != arguments.end())
    {
        auto arg = (*it).second;
        glDisableVertexAttribArray(arg->location);
        it++;
    }
}

ShaderProgram *ShaderProgram::simple()
{
    auto vertex = new VertexShader("assets/Simple.vs");
    auto fragment = new FragmentShader("assets/Simple.fs");
    auto program = new ShaderProgram(vertex, fragment);
    
    return program;
}

void ShaderProgram::setUniform(const std::string &name, GLvoid *value, ShaderArgument::Type type)
{
    setArgument(name, value, 1, type, true);
}

void ShaderProgram::setAttribute(const std::string &name, GLvoid *value, GLuint size, ShaderArgument::Type type)
{
    setArgument(name, value, size, type, false);
}

void ShaderProgram::setArgument(const std::string &name, GLvoid *value, GLuint size, ShaderArgument::Type type, GLboolean isUniform)
{
    begin();
    
    ShaderArgument *arg;

    auto it = arguments.find(name);
    if (it == arguments.end())
        arg = new ShaderArgument(type, size);
    else
    {
        arg = it->second;
        arg->type = type;
        arg->count = size;
    }
    
    arg->isUniform = isUniform;
    arg->location = isUniform ? glGetUniformLocation(id, name.c_str()) : glGetAttribLocation(id, name.c_str());
    arg->value = value;
    arg->load();
    
    arguments[name] = arg;
    
    end();
}

GLuint ShaderProgram::getId()
{
    return id;
}

VertexShader *ShaderProgram::getVertex()
{
    return vertex;
}

FragmentShader *ShaderProgram::getFragment()
{
    return fragment;
}
