//
//  main.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Application.hpp"

int main(int argc, const char * argv[])
{
    auto app = new Application("OpenGL Application", 800, 600);
    app->run();
    
    delete app;
    
    return 0;
}
