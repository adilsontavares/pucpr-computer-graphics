//
//  Box.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include "Mesh.hpp"

class Box : public Mesh
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
    
    void resetMesh();
};

#endif /* Box_hpp */
