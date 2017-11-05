//
//  RenderNode.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "RenderNode.hpp"

RenderNode::RenderNode()
{
    program = Program::simple();
}

void RenderNode::setProgram(Program *program)
{
    this->program = program;
}

Program *RenderNode::getProgram()
{
    return program;
}

void RenderNode::draw()
{
}
