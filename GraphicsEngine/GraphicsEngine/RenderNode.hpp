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
#include "Program.hpp"

class RenderNode : public Node
{
public:
    
    RenderNode();
    
    void setProgram(Program *program);
    Program *getProgram();
    
    virtual void draw();
    
protected:
    
    Program *program;
};

#endif /* RenderNode_hpp */
