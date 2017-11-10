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
#include "Square.hpp"
#include "Cylinder.hpp"
#include "Triangle.hpp"
#include "LineNode.hpp"
#include "Cone.hpp"
#include "FragmentShader.hpp"

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
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
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
    cone = new Cone(0.5, 1);
    coneNode = new MeshNode(cone);
    addChild(coneNode);
    
    camera = new Camera();
    camera->setPosition(Vector3(0, 0, -10));
    addChild(camera);
}

void Application::update()
{
    static float x = 0;
    x += 0.03;
    
    hue = sin(x) * 0.5 + 0.5;
    cone->setRadius((sin(x) * 0.5 + 0.5) * 0.9 + 0.1);
    cone->setDivisions(GLuint((sin(x) * 0.5 + 0.5) * 20 + 3));
    
    for (auto node : nodes)
    {
        if (node != camera)
        {
            node->setRotation(Vector3(0, x * 4.0, 0));
            node->update(0);
        }
    }
    
    auto radius = 1.5;
    
    camera->setPosition(Vector3(cos(x) * radius, sin(x) * radius, -3));
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
