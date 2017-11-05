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
    
    void update(float delta);    
    
    virtual void setPosition(Vector3 position);
    virtual void setRotation(Vector3 rotation);
    virtual void setScale(Vector3 scale);
    
    Vector3 getPosition();
    Vector3 getRotation();
    Vector3 getScale();
    
    glm::mat4 getMatrix();
    
    virtual void draw();
    
protected:
    
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

#endif /* Node_hpp */
