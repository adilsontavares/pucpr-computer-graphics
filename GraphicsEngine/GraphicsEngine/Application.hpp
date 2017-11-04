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

#include "Size.hpp"
#include "Node.hpp"

class Application
{
public:
    
    void run();
    
    Application(std::string title, int width, int height);
    ~Application();
    
    void addChild(Node *node);
    void removeChild(Node *node);
    
private:
    
    std::vector<Node*> nodes;
    
    Size windowSize;
    std::string windowTitle;
    
    GLFWwindow *window;
    
    void init();
    void createWindow();
    void setupGlew();
    void setupGL();
    void setupNodes();
    
    void mainLoop();
    
    void update();
    void render();
};

#endif /* Application_hpp */
