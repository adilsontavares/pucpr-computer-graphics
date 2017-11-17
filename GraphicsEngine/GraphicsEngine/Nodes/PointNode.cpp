//
//  PointNode.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "PointNode.hpp"

PointNode::PointNode() : RenderNode()
{
    glGenBuffers(1, &vertexBuffer);
    setPosition(position);
    
    glGenBuffers(1, &colorBuffer);
    setColor(color);
    
    glGenVertexArrays(1, &arrayId);
    glBindVertexArray(arrayId);
}

void PointNode::setPosition(Vector3 position)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, position.bytes(), &position, GL_DYNAMIC_DRAW);
    
    RenderNode::setPosition(position);
}

void PointNode::setColor(Color color)
{
    this->color = color;
    
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, color.bytes(), &color, GL_DYNAMIC_DRAW);
}

Color PointNode::getColor()
{
    return color;
}

void PointNode::draw(glm::mat4 base)
{
    if (program)
    {
        program->begin();
        
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        
        glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, 0, 0);
        
        auto mvp = glGetUniformLocation(program->getId(), "MVP");
        auto matrix = base * getMatrix();
        glUniformMatrix4fv(mvp, 1, GL_FALSE, &matrix[0][0]);
        
        glDrawArrays(GL_POINTS, 0, 3);
        
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
        
        program->end();
    }
}
