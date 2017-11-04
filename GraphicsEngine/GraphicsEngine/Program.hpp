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
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

class Program
{
public:
    
    Program(VertexShader *vertex, FragmentShader *fragment);
    
    void use();
    
    static Program *simple();
    
    GLuint getId();
    
    VertexShader *getVertex();
    FragmentShader *getFragment();
    
private:
    
    GLuint id;
    
    VertexShader *vertex;
    FragmentShader *fragment;
};

#endif /* Program_hpp */
