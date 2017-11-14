//
//  Application.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Application.hpp"
#include <cassert>
#include "File.hpp"
#include "FragmentShader.hpp"
#include "DisplayFile.hpp"

using namespace std;

Application::Application(string title, int width, int height)
{
    camera = 0;
    
    windowTitle = title;
    windowSize = Size(width, height);
    
    init();
}

void Application::init()
{
    assert(glfwInit());
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
}

void Application::run()
{
    createWindow();
    setupGlew();
    setupGL();
    setupCamera();
    setupNodes();
    
    mainLoop();
}

void Application::setupCamera()
{
    camera = new Camera();
    camera->setAspectRatio(windowSize.width / windowSize.height);
    camera->setPosition(Vector3(0, 0, 10));
    camera->lookAt(Vector3());
    addChild(camera);
}

void Application::setupNodes()
{
    auto file = DisplayFile("assets/DisplayFile.json");
    auto objects = file.getObjects();
    
    for (auto object : objects)
    {
        auto node = object->instantiate();
        addChild(node);
    }
}

void Application::update()
{
    for (auto node : nodes)
    {
        if (node != camera)
            node->update(0);
    }
}

void Application::render()
{
    if (!camera)
        return;
    
    glm::mat4 base = camera->getMatrix();
    
    for (auto node : nodes)
        node->draw(base);
}

void Application::mainLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        glPushMatrix();
        
        update();
        render();
        
        glPopMatrix();
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}

void Application::createWindow()
{
    window = glfwCreateWindow((int)windowSize.width, (int)windowSize.height, windowTitle.c_str(), 0, 0);
    assert(window);
    
    glfwMakeContextCurrent(window);
}

void Application::setupGlew()
{
    assert(glewInit() == GLEW_OK);
}

void Application::setupGL()
{
    glClearColor(0.15, 0.15, 0.15, 1.0);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_POLYGON_SMOOTH_HINT);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    
//    glEnable(GL_MULTISAMPLE);
}

void Application::addChild(Node *node)
{
    nodes.push_back(node);
}

void Application::removeChild(Node *node)
{
}

Application::~Application()
{
    glfwTerminate();
}
