//
//  Program.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Program_hpp
#define Program_hpp

#include <stdio.h>
#include "Shader.hpp"

class Program
{
public:
    
    Program(Shader *vertex, Shader *fragment);
    
    void use();
    
    static Program *simple();
    
    GLuint getId();
    
private:
    
    GLuint id;
    
    Shader *vertex;
    Shader *fragment;
};

#endif /* Program_hpp */
