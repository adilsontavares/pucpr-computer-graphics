//
//  PointNode.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef PointNode_hpp
#define PointNode_hpp

#include "RenderNode.hpp"
#include "Color.hpp"

class PointNode : public RenderNode
{
public:
    
    PointNode();
    
    virtual void draw();
    
    virtual void setPosition(Vector3 position);
    
    void setColor(Color color);
    Color getColor();
    
protected:
    
    Color color;
    
    GLuint vertexBuffer;
    GLuint colorBuffer;
    GLuint arrayId;
};

#endif /* PointNode_hpp */
