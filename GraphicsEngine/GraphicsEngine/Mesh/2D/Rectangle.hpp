//
//  Rectangle.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 06/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Primitive.hpp"

class Rectangle : public Primitive
{
public:
    
    Rectangle(GLfloat width, GLfloat height);
    
    void setWidth(GLfloat width);
    void setHeight(GLfloat height);
    
    GLfloat getWidth();
    GLfloat getHeight();
    
protected:
    
    GLfloat width;
    GLfloat height;
    
    virtual void resetMesh();
};

#endif /* Rectangle_hpp */
