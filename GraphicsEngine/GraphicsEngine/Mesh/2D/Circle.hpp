//
//  Circle.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 06/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include "Primitive.hpp"

class Circle : public Primitive
{
public:
    
    Circle(GLfloat radius, GLuint divisions = 8);
    
    void setRadius(GLfloat radius);
    void setDivisions(GLuint divisions);
    
    GLfloat getRadius();
    GLuint getDivisions();
    
protected:
    
    GLfloat radius;
    GLuint divisions;
    
    virtual void resetMesh();
};

#endif /* Circle_hpp */
