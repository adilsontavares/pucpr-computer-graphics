//
//  Cylinder.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Cylinder_hpp
#define Cylinder_hpp

#include "Primitive.hpp"

class Cylinder : public Primitive
{
public:
    
    Cylinder(GLfloat radius, GLfloat height, GLuint divisions = 8);
    
    void setRadius(GLfloat radius);
    void setHeight(GLfloat height);
    void setDivisions(GLuint divisions);
    
    GLfloat getRadius();
    GLfloat getHeight();
    GLuint getDivisions();
    
    static Cylinder *create(DisplayFileObject *config);
    
protected:
    
    GLfloat radius;
    GLfloat height;
    GLuint divisions;
    
    virtual void generate();
};

#endif /* Cylinder_hpp */
