//
//  DisplayFileObject.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 14/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef DisplayFileObject_hpp
#define DisplayFileObject_hpp

#include "Node.hpp"
#include "Color.hpp"

#include <stdio.h>
#include <rapidjson/document.h>

class Mesh;
class MeshNode;

class DisplayFileObject
{
private:
    
    const rapidjson::Value& value;
    
public:
    
    enum Type
    {
        UNKNOWN,
        
        RECTANGLE,
        SQUARE,
        CIRCLE,
        TRIANGLE,
        
        POINT,
        LINE,
        BOX,
        CUBE,
        CYLINDER,
        SPHERE,
        CONE,
        
        CAMERA
    };
    
    DisplayFileObject(const rapidjson::Value& value);
    
    Type getType();
    
    Node *instantiate();
    
    GLint getInt(const char *path);
    GLfloat getFloat(const char *path);
    Color getColor(const char *path);
    GLboolean getBool(const char *path);
    Vector3 getVector3(const char *path);
    
    void assertInt(const char *path);
    void assertFloat(const char *path);
    void assertColor(const char *path);
    void assertBool(const char *path);
    void assertVector3(const char *path);
    
    GLboolean hasProperty(const char *path);
};

#endif /* DisplayFileObject_hpp */
