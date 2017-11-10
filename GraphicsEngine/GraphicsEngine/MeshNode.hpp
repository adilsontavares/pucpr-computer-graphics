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

class MeshNode : public RenderNode
{
public:
    
    MeshNode();
    MeshNode(Mesh *mesh);
    
    void setMesh(Mesh *mesh);
    Mesh *getMesh();
  
    virtual void update(GLfloat delta);
    virtual void draw(glm::mat4 base);
    
private:
    
    GLuint vertexBuffer;
    GLuint elementBuffer;
    GLuint colorBuffer;
    
    glm::mat4 *matrix;
    GLuint arrayId;
    Mesh *mesh;
    
    void updateBuffers();
};

#endif /* MeshNode_hpp */
