//
//  Cube.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include "Box.hpp"

class Cube : public Box
{
public:
    
    Cube(GLfloat size);
    
    void setSize(GLfloat size);
    GLfloat getSize();
    
    static Cube *create(DisplayFileObject *config);
    
protected:
    
    GLfloat size;
};

#endif /* Cube_hpp */
