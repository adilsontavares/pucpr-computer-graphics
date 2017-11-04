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

MeshNode::MeshNode()
{
    this->mesh = 0;
    this->program = Program::simple();
}

MeshNode::MeshNode(Mesh *mesh)
{
    MeshNode();
    setMesh(mesh);
}

void MeshNode::setMesh(Mesh *mesh)
{
    this->mesh = mesh;
    if (!mesh)
        return;
    
    mesh->assertConsistency();
    
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * 3 * sizeof(mesh->vertices[0]), mesh->vertices.data(), GL_STATIC_DRAW);
    
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->faces.size() * sizeof(mesh->faces[0]), mesh->faces.data(), GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &arrayId);
    glBindVertexArray(arrayId);
}

void MeshNode::setProgram(Program *program)
{
    this->program = program;
}

Mesh *MeshNode::getMesh()
{
    return mesh;
}

void MeshNode::draw()
{
    if (mesh && program)
    {
        program->use();
        
        glEnableVertexAttribArray(0);
        
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
        glDrawElements(GL_TRIANGLES, GLsizei(mesh->faces.size()), GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
    }
    
    Node::draw();
}
