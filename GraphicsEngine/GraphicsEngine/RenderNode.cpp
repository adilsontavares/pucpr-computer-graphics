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
    program = ShaderProgram::simple();
}

void RenderNode::setProgram(ShaderProgram *program)
{
    this->program = program;
}

ShaderProgram *RenderNode::getProgram()
{
    return program;
}

void RenderNode::draw(glm::mat4 base)
{
}
