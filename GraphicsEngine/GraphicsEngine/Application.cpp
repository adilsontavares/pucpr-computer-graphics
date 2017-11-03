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
#include "Program.hpp"

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
    float points[] = {
        0, 0.5, 0,
        0.5, -0.5, 0,
        -0.5, -0.5, 0
    };
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    Shader *vertex = new VertexShader("assets/Shader.vs");
    Shader *fragment = new FragmentShader("assets/Shader.fs");
    Program *program = new Program(vertex, fragment);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        program->use();
        glBindVertexArray(vao);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
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
