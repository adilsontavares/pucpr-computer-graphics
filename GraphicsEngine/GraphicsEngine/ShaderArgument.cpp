//
//  ShaderArgument.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 09/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "ShaderArgument.hpp"
#include <iostream>

ShaderArgument::ShaderArgument(ShaderArgument::Type type, GLuint count)
{
    this->buffer = 0;
    this->type = type;
    this->count = count;
}

void ShaderArgument::set()
{
    if (isUniform)
        setUniform();
    else
        setAttribute();
}

void ShaderArgument::setUniform()
{
    if (dataType == GL_FLOAT)
    {
        if (isMatrix)
            glUniformMatrix4fv(location, 1, GL_FALSE, (GLfloat*)value);
        else if (stepSize == 1)
            glUniform1f(location, *(GLfloat*)value);
        else if (stepSize == 2)
            glUniform2f(location, *(GLfloat*)value, *(((GLfloat*)value) + 1));
        else if (stepSize == 3)
            glUniform3f(location, *(GLfloat*)value, *(((GLfloat*)value) + 1), *(((GLfloat*)value) + 2));
        else if (stepSize == 4)
            glUniform4f(location, *(GLfloat*)value, *(((GLfloat*)value) + 1), *(((GLfloat*)value) + 2), *(((GLfloat*)value) + 3));
    }
}

void ShaderArgument::setAttribute()
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(location, stepSize, dataType, normalized, 0, 0);
}

void ShaderArgument::load()
{
    isMatrix = false;
    normalized = false;
    dataType = GL_FLOAT;
    stepSize = 1;
    
    GLuint elementSize = sizeof(GLfloat);
    
    switch (type)
    {
        case ShaderArgument::Type::COLOR:
            stepSize = 4;
            normalized = true;
            break;
            
        case ShaderArgument::Type::FLOAT:
            break;
            
        case ShaderArgument::Type::MATRIX4:
            isMatrix = true;
            break;
            
        case ShaderArgument::Type::VECTOR3:
            stepSize = 3;
            break;
    }
    
    bytes = elementSize * stepSize * count;
    
    if (!isUniform)
    {
        if (!buffer)
            glGenBuffers(1, &buffer);
        
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, bytes, value, GL_DYNAMIC_DRAW);
    }
}

