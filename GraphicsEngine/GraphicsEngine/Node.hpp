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
#include "Math.hpp"
#include <rapidjson/document.h>

class DisplayFileObject;

class Node
{
public:
    
    Node();
    
    virtual void update(GLfloat delta);    
    
    virtual void setPosition(Vector3 position);
    virtual void setRotation(Vector3 rotation);
    virtual void setScale(Vector3 scale);
    
    Vector3 getPosition();
    Vector3 getRotation();
    Vector3 getScale();
    
    virtual glm::mat4 getMatrix();
    
    virtual void draw(glm::mat4 base);
    
protected:
    
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    
    virtual void loadConfig(DisplayFileObject *config);
};

#endif /* Node_hpp */
