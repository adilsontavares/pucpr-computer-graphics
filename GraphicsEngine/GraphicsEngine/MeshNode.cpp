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
    glGenVertexArrays(1, &arrayId);
    glBindVertexArray(arrayId);
    
    matrix = new glm::mat4(1);
    program->setUniform("MVP", matrix, ShaderArgument::Type::MATRIX4);
}

MeshNode::MeshNode(Mesh *mesh) : MeshNode()
{
    addMesh(mesh);
}

MeshNode *MeshNode::create(DisplayFileObject *config)
{
    auto node = new MeshNode();
    node->loadConfig(config);
    
    return node;
}

void MeshNode::addMesh(Mesh *mesh)
{
    if (!mesh)
        return;
    
    mesh->assertConsistency();
    
    meshes.push_back(mesh);
}

void MeshNode::update(GLfloat delta)
{
}

void MeshNode::updateBuffers()
{
    for (auto mesh : meshes)
    {
        mesh->updateBuffers(program);
        mesh->setDirty(false);
    }
}

GLboolean MeshNode::isDirty()
{
    for (auto mesh : meshes)
        if (mesh->isDirty())
            return true;
            
    return false;
}

void MeshNode::draw(glm::mat4 base)
{
    if (!meshes.empty() && program)
    {
        if (isDirty())
            updateBuffers();
        
        *matrix = base * getMatrix();
        
        program->begin();
        
        for (auto mesh : meshes)
            mesh->render();
        
        program->end();
    }
    
    Node::draw(base);
}
