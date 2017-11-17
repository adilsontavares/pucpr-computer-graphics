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
#include "MainScene.hpp"

using namespace std;

Application *Application::main;

void Application::setupScene()
{
    scene = new MainScene();
    scene->init();
}

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
    glfwWindowHint(GLFW_SAMPLES, 4);
    
    oldTime = std::chrono::steady_clock::now();
}

void Application::run()
{
    createWindow();
    setupGlew();
    setupGL();
    setupScene();
    setupInputs();
    
    mainLoop();
}

void Application::setupInputs()
{
    glfwSetKeyCallback(window, Application::handleKey);
}

GLFWwindow *Application::getMainWindow()
{
    return window;
}

void Application::handleKey(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    auto scene = Application::main->scene;
    
    if (!scene)
        return;
    
    if (action == GLFW_PRESS)
        scene->onKeyDown(key);
    else if (action == GLFW_RELEASE)
        scene->onKeyUp(key);
    else if (action == GLFW_REPEAT)
        scene->onKeyRepeat(key);
}

void Application::handleWindowResize(GLFWwindow *window, int width, int height)
{
    auto app = Application::main;
    app->windowSize = Size(width, height);
}

void Application::render()
{
    if (!scene)
        return;
    
    if (scene->mainCamera)
        scene->mainCamera->setAspectRatio(windowSize.width / windowSize.height);
        
    scene->render(glm::mat4(1));
}

void Application::update()
{
    if (!scene)
        return;
    
    auto time = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::duration<double>>(time - oldTime).count();

    scene->update(delta);
    
    oldTime = time;
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
    glfwSetWindowSizeCallback(window, Application::handleWindowResize);
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
    
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_FRONT);
//    glFrontFace(GL_CW);
}

Application::~Application()
{
    glfwTerminate();
}
