//
//  Scene.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 16/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <iostream>
#include <GL/glew.h>
#include <vector>

#include "Camera.hpp"

class Scene
{
public:
    
    Scene();
    
    virtual void init();
    virtual void update(GLfloat delta);
    virtual void render(glm::mat4 base);
    
    virtual void onKeyDown(int key);
    virtual void onKeyUp(int key);
    virtual void onKeyRepeat(int key);
    
    bool isKeyDown(int key);
    bool isKeyUp(int key);
    
    Camera *mainCamera;
    std::vector<Node*> nodes;
    
    void addChild(Node *node);
    void removeChild(Node *node);
    
    void loadDisplayFile(const char *path);
};

#endif /* Scene_hpp */
