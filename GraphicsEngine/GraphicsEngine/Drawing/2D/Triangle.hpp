//
//  Triangle.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 07/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include "Primitive.hpp"

class Triangle: public Primitive
{
public:
    
    Triangle(GLfloat radius);
    
    void setRadius(GLfloat radius);
    GLfloat getRadius();
    
protected:
    
    GLfloat radius;
    
    virtual void generate();
};

#endif /* Triangle_hpp */
