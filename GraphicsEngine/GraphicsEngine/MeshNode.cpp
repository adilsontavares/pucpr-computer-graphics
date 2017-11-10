//
//  MeshNode.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "MeshNode.hpp"
#include "Mesh.hpp"
#include <cassert>

MeshNode::MeshNode() : RenderNode()
{
    this->mesh = 0;
    
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);
    glGenBuffers(1, &colorBuffer);
    glGenVertexArrays(1, &arrayId);
    glBindVertexArray(arrayId);
    
    matrix = new glm::mat4(1);
    program->setUniform("MVP", matrix, ShaderArgument::Type::MATRIX4);
}

MeshNode::MeshNode(Mesh *mesh) : MeshNode()
{
    setMesh(mesh);
}

void MeshNode::setMesh(Mesh *mesh)
{
    this->mesh = mesh;
    if (!mesh)
        return;
    
    mesh->assertConsistency();
}

void MeshNode::update(GLfloat delta)
{
}

void MeshNode::updateBuffers()
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * 3 * sizeof(mesh->vertices[0]), mesh->vertices.data(), GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->faces.size() * sizeof(mesh->faces[0]), mesh->faces.data(), GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, mesh->colors.size() * sizeof(mesh->colors[0]), mesh->colors.data(), GL_DYNAMIC_DRAW);
    
    program->setAttribute("position", &mesh->vertices[0], GLuint(mesh->vertices.size()), ShaderArgument::Type::VECTOR3);
    program->setAttribute("vertexColor", &mesh->colors[0], GLuint(mesh->colors.size()), ShaderArgument::Type::COLOR);
}

Mesh *MeshNode::getMesh()
{
    return mesh;
}

void MeshNode::draw(glm::mat4 base)
{
    if (mesh && program)
    {
        if (mesh->isDirty())
        {
            updateBuffers();
            mesh->setDirty(false);
        }
        
        *matrix = base * getMatrix();
        
        program->begin();
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
        glDrawElements(GL_TRIANGLES, GLsizei(mesh->faces.size()), GL_UNSIGNED_INT, 0);
        
        program->end();
    }
    
    Node::draw(base);
}
