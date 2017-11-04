//
//  Node.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Vector3.hpp"

class Node
{
public:
    
    Node();
    virtual void draw();
 
    void setPosition(Vector3 position);
    void setRotation(Vector3 rotation);
    void setScale(Vector3 scale);
    
    Vector3 getPosition();
    Vector3 getRotation();
    Vector3 getScale();
    
    glm::mat4 getMatrix();
    
private:
    
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

#endif /* Node_hpp */
