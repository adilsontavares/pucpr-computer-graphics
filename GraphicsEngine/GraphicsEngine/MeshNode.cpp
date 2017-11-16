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
    matrix = new glm::mat4(1);
    program->setUniform("MVP", matrix, ShaderArgument::Type::MATRIX4);
}

MeshNode::MeshNode(Mesh mesh) : MeshNode()
{
    addMesh(mesh);
}

void MeshNode::removeAllMeshes()
{
    meshes.clear();
}

MeshNode *MeshNode::create(DisplayFileObject *config)
{
    auto node = new MeshNode();
    node->loadConfig(config);
    
    return node;
}

void MeshNode::addMesh(Mesh mesh)
{
    mesh.assertConsistency();
    meshes.push_back(mesh);
}

void MeshNode::update(GLfloat delta)
{
}

void MeshNode::updateBuffers()
{
    for (auto it = meshes.begin(); it != meshes.end(); ++it)
    {
        it->updateBuffers(program);
        it->setDirty(false);
    }
}

GLboolean MeshNode::isDirty()
{
    for (auto it = meshes.begin(); it != meshes.end(); ++it)
        if (it->isDirty())
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
        
        for (auto it = meshes.begin(); it != meshes.end(); ++it)
            it->render();
        
        program->end();
    }
    
    Node::draw(base);
}
