//
//  RenderNode.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef RenderNode_hpp
#define RenderNode_hpp

#include "Node.hpp"
#include "ShaderProgram.hpp"

class RenderNode : public Node
{
public:
    
    RenderNode();
    
    void setProgram(ShaderProgram *program);
    ShaderProgram *getProgram();
    
    virtual void draw(glm::mat4 base);
    
protected:
    
    ShaderProgram *program;
};

#endif /* RenderNode_hpp */
