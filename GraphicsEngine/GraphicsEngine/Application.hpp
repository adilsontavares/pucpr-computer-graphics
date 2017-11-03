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
#include <cstring>

#include "Size.hpp"

class Application
{
public:
    
    void run();
    
    Application(std::string title, int width, int height);
    ~Application();
    
private:
    
    Size windowSize;
    std::string windowTitle;
    
    GLFWwindow *window;
    
    void init();
    void createWindow();
    void setupGlew();
    void setupGL();
    
    void mainLoop();
};

#endif /* Application_hpp */
