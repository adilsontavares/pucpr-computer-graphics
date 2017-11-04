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

#include "VertexShader.hpp"
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
    
    mainLoop();
}

void Application::mainLoop()
{
    Mesh *mesh = new Mesh();
    mesh->setVertices((Vector3[]){
        Vector3(0, 0, 0),
        Vector3(1, 1, 0),
        Vector3(1, 0, 0),
        Vector3(1, -1, 0)
    }, 4);
    
    mesh->setFaces((GLuint[]) { 0, 1, 2, 2, 3, 0 }, 6);
    mesh->setColors((Color[]) {
        Color::red(),
        Color::green(),
        Color::blue()
    }, 3);
    
    auto node = new MeshNode();
    node->setMesh(mesh);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        node->draw();
        
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
    glClearColor(0.2, 0.2, 0.2, 1.0);
}

Application::~Application()
{
    glfwTerminate();
}
