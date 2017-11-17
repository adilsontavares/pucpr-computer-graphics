//
//  LineNode.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 07/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "LineNode.hpp"

LineNode::LineNode(Vector3 origin, Vector3 destin)
{
    this->origin = origin;
    this->destin = destin;
    
    glGenBuffers(1, &vertexBuffer);
    updateVertexBuffer();
    
    glGenBuffers(1, &colorBuffer);
    updateColorBuffer();
    
    glGenVertexArrays(1, &arrayId);
    glBindVertexArray(arrayId);
    
    updateVertexBuffer();
}

void LineNode::setOriginColor(Color color)
{
    this->originColor = color;
    updateColorBuffer();
}

void LineNode::setDestinationColor(Color color)
{
    this->destinColor = color;
    updateColorBuffer();
}

void LineNode::updateColorBuffer()
{
    Color colors[2] = {
        originColor, destinColor
    };
    
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, originColor.bytes() * 2, colors, GL_DYNAMIC_DRAW);
}

void LineNode::setOrigin(Vector3 origin)
{
    this->origin = origin;
    updateVertexBuffer();
}

void LineNode::setDestination(Vector3 destin)
{
    this->destin = destin;
    updateVertexBuffer();
}

void LineNode::updateVertexBuffer()
{
    Vector3 points[2] = {
        origin, destin
    };
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, origin.bytes() * 2, points, GL_DYNAMIC_DRAW);
}

Vector3 LineNode::getOrigin()
{
    return origin;
}

Vector3 LineNode::getDestination()
{
    return destin;
}

void LineNode::draw(glm::mat4 base)
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
        
        glDrawArrays(GL_LINES, 0, 2);
        
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
        
        program->end();
    }
}
