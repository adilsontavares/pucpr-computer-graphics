//
//  Node.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Node.hpp"
#include <glm/gtc/matrix_transform.hpp>

Node::Node()
{
    position = Vector3();
    rotation = Vector3();
    scale = Vector3(1);
}

void Node::update(float delta)
{
}

void Node::draw()
{
}

void Node::setPosition(Vector3 position)
{
    this->position = position;
}

void Node::setRotation(Vector3 rotation)
{
    this->rotation = rotation;
}

void Node::setScale(Vector3 scale)
{
    this->scale = scale;
}

Vector3 Node::getPosition()
{
    return position;
}

Vector3 Node::getRotation()
{
    return rotation;
}

Vector3 Node::getScale()
{
    return scale;
}

glm::mat4 Node::getMatrix()
{
    auto mat = glm::mat4(1);
    
    mat = glm::translate(mat, glm::vec3(position.x, position.y, position.z));
    mat = glm::rotate(mat, rotation.x, glm::vec3(1, 0, 0));
    mat = glm::rotate(mat, rotation.y, glm::vec3(0, 1, 0));
    mat = glm::rotate(mat, rotation.z, glm::vec3(0, 0, 1));
    mat = glm::scale(mat, glm::vec3(scale.x, scale.y, scale.z));
    
    return mat;
}

