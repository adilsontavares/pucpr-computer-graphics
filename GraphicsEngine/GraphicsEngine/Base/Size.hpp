//
//  Header.h
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <GL/glew.h>

class Size
{
public:
    
    GLfloat width;
    GLfloat height;
    
    Size()
    {
        width = height = 0;
    }
    
    Size(GLfloat width, GLfloat height)
    {
        this->width = width;
        this->height = height;
    }
};

#endif /* Header_h */
