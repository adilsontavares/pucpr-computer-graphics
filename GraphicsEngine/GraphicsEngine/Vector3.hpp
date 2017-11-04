//
//  Vector3.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <stdio.h>
#include <GL/glew.h>

class Vector3
{
public:
    
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
    Vector3();
    Vector3(GLfloat v);
    Vector3(GLfloat x, GLfloat y, GLfloat z);
    
    GLfloat magnitude();
};

#endif /* Vector3_hpp */
