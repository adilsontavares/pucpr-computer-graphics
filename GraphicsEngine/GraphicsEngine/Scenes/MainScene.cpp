//
//  MainScene.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 17/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "MainScene.hpp"

#include <GLFW/glfw3.h>
#include <glm/gtx/transform.hpp>

void MainScene::init()
{
    mainCamera->setPosition(Vector3(0, 0, 10));
    mainCamera->lookAt(Vector3());
    
    loadDisplayFile("assets/DisplayFile.json");
}

void MainScene::update(GLfloat delta)
{
    Scene::update(delta);
    
    if (isKeyDown(GLFW_KEY_UP))
        orbit.x += 90 * delta;
    if (isKeyDown(GLFW_KEY_DOWN))
        orbit.x -= 90 * delta;
    
    if (isKeyDown(GLFW_KEY_RIGHT))
        orbit.y += 90 * delta;
    if (isKeyDown(GLFW_KEY_LEFT))
        orbit.y -= 90 * delta;
    
    auto mat = glm::mat4(1);
    mat = glm::rotate(mat, glm::radians(orbit.x), glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, glm::radians(orbit.y), glm::vec3(0, 1, 0));
    
    mainCamera->setPosition(Vector3(mat * glm::vec4(0, 0, -10, 1)));
}
