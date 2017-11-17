//
//  ShaderProgram.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef ShaderProgram_hpp
#define ShaderProgram_hpp

#include <stdio.h>
#include "VertexShader.hpp"
#include "FragmentShader.hpp"
#include "ShaderArgument.hpp"

class ShaderProgram
{
public:
    
    ShaderProgram(VertexShader *vertex, FragmentShader *fragment);
    
    static ShaderProgram *simple();
    
    GLuint getId();
    
    VertexShader *getVertex();
    FragmentShader *getFragment();
    
    void setUniform(const std::string& name, GLvoid *value, ShaderArgument::Type type);
    void setAttribute(const std::string& name, GLvoid *value, GLuint size, ShaderArgument::Type type);
    
    void begin();
    void end();
    
private:
    
    GLuint id;
    std::map<std::string, ShaderArgument*> arguments;
    
    void setArgument(const std::string& name, GLvoid *value, GLuint size, ShaderArgument::Type type, GLboolean isUniform);
    
    VertexShader *vertex;
    FragmentShader *fragment;
};

#endif /* ShaderProgram_hpp */
