//
//  Application.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>

#include "Size.hpp"
#include "Scene.hpp"

class Application
{
public:
    
    void run();
    
    Application(std::string title, int width, int height);
    ~Application();
    
    GLFWwindow *getMainWindow();
    
    static Application *main;
    
private:
    
    Scene *scene;
    
    std::chrono::time_point<std::chrono::steady_clock> oldTime;
    
    Size windowSize;
    std::string windowTitle;
    
    GLFWwindow *window;
    
    void init();
    void createWindow();
    void setupGlew();
    void setupGL();
    void setupInputs();
    void setupScene();
    
    void mainLoop();
    
    void update();
    void render();
    
    static void handleKey(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void handleWindowResize(GLFWwindow *window, int width, int height);
};

#endif /* Application_hpp */
