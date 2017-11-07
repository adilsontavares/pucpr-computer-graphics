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

class Mesh
{
public:
    
    std::vector<Vector3> vertices;
    std::vector<GLuint> faces;
    std::vector<Color> colors;
    
    void setVertices(Vector3 *vertices, GLuint count);
    void setFaces(GLuint *faces, GLuint count);
    void setColors(Color *colors, GLuint count);
    
    void assertConsistency();
    void clear();
    
protected:
    
    GLuint loopVertexIndex(GLuint index);
};

#endif /* Mesh_hpp */
