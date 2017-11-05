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
#include "MeshNode.hpp"
#include "Color.hpp"
#include "PointNode.hpp"
#include "Cube.hpp"

using namespace std;

Application::Application(string title, int width, int height)
{
    windowTitle = title;
    windowSize = Size(width, height);
    
    init();
}

void Application::init()
{
    assert(glfwInit());
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::run()
{
    createWindow();
    setupGlew();
    setupGL();
    setupNodes();
    
    mainLoop();
}

void Application::setupNodes()
{
    auto node = new PointNode();
    node->setColor(Color::green());
    addChild(node);
    
//    auto cube = new Cube(1);
//    auto cubeNode = new MeshNode(cube);
//    addChild(cubeNode);
}

void Application::update()
{
    for (auto node : nodes)
        node->update(0);
}

void Application::render()
{
    for (auto node : nodes)
        node->draw();
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
