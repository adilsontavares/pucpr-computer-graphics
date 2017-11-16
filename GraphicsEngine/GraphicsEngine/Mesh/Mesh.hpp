//
//  Mesh.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "Vector3.hpp"
#include "Color.hpp"
#include "DisplayFileObject.hpp"
#include "ShaderProgram.hpp"

class Mesh
{
public:
    
    Mesh();
    
    std::string name;
    std::vector<Vector3> vertices;
    std::vector<GLuint> faces;
    std::vector<Color> colors;
    
    Color baseColor;
    
    void setVertices(Vector3 *vertices, GLuint count);
    void setFaces(GLuint *faces, GLuint count);
    void setColors(Color *colors, GLuint count);
    
    void assertConsistency();
    void clear();
    
    GLboolean isDirty();
    void setDirty(GLboolean dirty);

    void setDrawMode(GLuint mode);
    GLuint getDrawMode();
    
    void setName(const std::string& name);
    std::string getName();
    
    void updateBuffers(ShaderProgram *program);
    void render();
    
protected:
    
    GLuint arrayId;
    GLuint vertexBuffer;
    GLuint colorBuffer;
    GLuint elementBuffer;
    
    GLuint drawMode;
    GLboolean dirty;
    
    GLuint loopVertexIndex(GLuint index);
};

#endif /* Mesh_hpp */
