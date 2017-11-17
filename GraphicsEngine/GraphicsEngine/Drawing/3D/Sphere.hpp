//
//  Sphere.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "Primitive.hpp"

class Sphere : public Primitive
{
public:
    
    Sphere(GLfloat radius, GLuint divisions = 8);
    
    static Sphere *create(DisplayFileObject *config);
    
    void setDivisions(GLuint divisions);
    void setRadius(GLfloat radius);
    
    GLuint getDivisions();
    GLfloat getRadius();
    
protected:
    
    GLfloat radius;
    GLuint divisions;
    
    virtual void generate();
};

#endif /* Sphere_hpp */
