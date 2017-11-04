//
//  Cone.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Cone_hpp
#define Cone_hpp

#include "Primitive.hpp"

class Cone : public Primitive
{
public:
    
    Cone(GLfloat radius, GLfloat height, GLuint divisions = 8);
    
    void setDivisions(GLuint divisions);
    void setRadius(GLfloat radius);
    void setHeight(GLfloat height);
    
    GLuint getDivisions();
    GLfloat getRadius();
    GLfloat getHeight();
    
protected:
    
    GLuint divisions;
    GLfloat radius;
    GLfloat height;
    
    virtual void resetMesh();
};

#endif /* Cone_hpp */
