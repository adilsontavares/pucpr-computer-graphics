//
//  Shader.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Shader.hpp"
#include "File.hpp"

Shader::Shader(ShaderType type, const std::string& file)
{
    this->type = type;
    this->filePath = file;
    this->content = File::readAll(file);
    
    setup();
}

void Shader::setup()
{
    GLuint kind;
    
    switch (type)
    {
        case ShaderType::VERTEX: kind = GL_VERTEX_SHADER; break;
        case ShaderType::FRAGMENT: kind = GL_FRAGMENT_SHADER; break;
        default: assert(false);
    }
    
    const char *content = this->content.c_str();
    
    id = glCreateShader(kind);
    glShaderSource(id, 1, &content, 0);
    
    printf("Compiling shader %s: ", filePath.c_str());
    glCompileShader(id);
    
    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    
    if (success)
        printf("OK.\n");
    else
        printf("FAILED.\n");
}

GLuint Shader::getId()
{
    return id;
}
