//
//  Square.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 06/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    
    Square(GLfloat size);
    
    void setSize(GLfloat size);
    GLfloat getSize();
};

#endif /* Square_hpp */
