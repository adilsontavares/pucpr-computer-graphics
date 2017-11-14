//
//  MeshNode.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef MeshNode_hpp
#define MeshNode_hpp

#include "RenderNode.hpp"
#include "Mesh.hpp"
#include "ShaderProgram.hpp"
#include "DisplayFileObject.hpp"

class MeshNode : public RenderNode
{
public:
    
    MeshNode();
    MeshNode(Mesh *mesh);
    
    void addMesh(Mesh *mesh);
    void removeMesh(Mesh *mesh);
    void removeAllMeshes();
    
    std::vector<Mesh*> meshes;
  
    virtual void update(GLfloat delta);
    virtual void draw(glm::mat4 base);
    
    static MeshNode *create(DisplayFileObject *config);
    
    GLboolean isDirty();
    
private:
    
    glm::mat4 *matrix;
    GLuint arrayId;
    
    void updateBuffers();
};

#endif /* MeshNode_hpp */
