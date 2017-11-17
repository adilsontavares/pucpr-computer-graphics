//
//  Shader.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <map>

class Shader
{
public:
    
    enum Type
    {
        VERTEX,
        FRAGMENT
    };
    
    Shader(Type type, const std::string& file);
    
    GLuint getId();
    
private:
    
    GLuint id;
    
    Type type;
    std::string filePath;
    std::string content;
    
    void setup();
};

#endif /* Shader_hpp */
