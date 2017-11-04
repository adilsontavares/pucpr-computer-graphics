//
//  Color.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <GL/glew.h>

class Color
{
public:
    
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
    
    Color(GLfloat r, GLfloat g, GLfloat b);
    Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    
    static Color red();
    static Color green();
    static Color blue();
    static Color black();
    static Color gray();
    static Color white();
};

#endif /* Color_hpp */
