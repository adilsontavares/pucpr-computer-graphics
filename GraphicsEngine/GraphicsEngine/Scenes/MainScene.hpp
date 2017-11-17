//
//  MainScene.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 17/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include "Scene.hpp"
#include <glm/matrix.hpp>

class MainScene : public Scene
{
public:
    
    virtual void init();
    virtual void update(GLfloat delta);
    
private:
    
    Vector3 orbit;
};

#endif /* MainScene_hpp */
