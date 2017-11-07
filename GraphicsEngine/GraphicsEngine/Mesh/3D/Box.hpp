//
//  Box.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include "Primitive.hpp"

class Box : public Primitive
{
public:
    
    Box(GLfloat width, GLfloat height, GLfloat depth);
    
    void setWidth(GLfloat width);
    void setHeight(GLfloat height);
    void setDepth(GLfloat depth);
    
protected:
    
    GLfloat width;
    GLfloat height;
    GLfloat depth;
    
    virtual void generate();
};

#endif /* Box_hpp */
