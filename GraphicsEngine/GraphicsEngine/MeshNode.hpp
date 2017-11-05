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
#include "Program.hpp"

class MeshNode : public RenderNode
{
public:
    
    MeshNode();
    MeshNode(Mesh *mesh);
    
    void setMesh(Mesh *mesh);
    Mesh *getMesh();
  
    virtual void draw();
    
private:
    
    GLuint vertexBuffer;
    GLuint elementBuffer;
    GLuint colorBuffer;
    
    GLuint arrayId;
    
    Mesh *mesh;
};

#endif /* MeshNode_hpp */
