//
//  Scene.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 16/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Scene.hpp"
#include "DisplayFile.hpp"
#include "Application.hpp"

#include <GLFW/glfw3.h>

Scene::Scene()
{
    mainCamera = new Camera();
    addChild(mainCamera);
}

void Scene::init()
{
    
}

void Scene::render(glm::mat4 base)
{
    if (!mainCamera)
        return;
    
    glm::mat4 matrix = base * mainCamera->getMatrix();
    
    for (auto node : nodes)
        node->draw(matrix);
}

void Scene::update(GLfloat delta)
{
    for (auto node : nodes)
    {
        if (node != mainCamera)
            node->update(delta);
    }
}

bool Scene::isKeyDown(int key)
{
    auto app = Application::main;
    auto state = glfwGetKey(app->getMainWindow(), key);
    
    return state != GLFW_RELEASE;
}

bool Scene::isKeyUp(int key)
{
    return !isKeyDown(key);
}

void Scene::addChild(Node *node)
{
    nodes.push_back(node);
}

void Scene::removeChild(Node *node)
{
}

void Scene::loadDisplayFile(const char *path)
{
    auto file = DisplayFile("assets/DisplayFile.json");
    auto objects = file.getObjects();
    
    for (auto object : objects)
    {
        auto node = object->instantiate();
        addChild(node);
    }
}

void Scene::onKeyDown(int key)
{
}

void Scene::onKeyUp(int key)
{
}

void Scene::onKeyRepeat(int key)
{
}
