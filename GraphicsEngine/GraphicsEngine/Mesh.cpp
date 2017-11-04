//
//  Mesh.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Mesh.hpp"
#include <cassert>

void Mesh::setVertices(Vector3 *vertices, GLuint count)
{
    this->vertices.clear();
    
    for (GLuint i = 0; i < count; ++i)
        this->vertices.push_back(vertices[i]);
}

void Mesh::setFaces(GLuint *faces, GLuint count)
{
    this->faces.clear();
    
    for (GLuint i = 0; i < count; ++i)
        this->faces.push_back(faces[i]);
}

void Mesh::setColors(Color *colors, GLuint count)
{
    this->colors.clear();
    
    for (GLuint i = 0; i < count; ++i)
        this->colors.push_back(colors[i]);
}

void Mesh::assertConsistency()
{
    if (faces.size() % 3 != 0)
    {
        printf("Mesh face count (%d) must multiple of 3.\n", GLsizei(faces.size()));
        assert(false);
    }
    
    if (faces.empty())
    {
        printf("Mesh face count (%d) must not be zero.\n", GLsizei(faces.size()));
        assert(false);
    }
    
    if (vertices.empty())
    {
        printf("Mesh vertice count (%d) must not be zero.\n", GLsizei(vertices.size()));
        assert(false);
    }
    
    while (colors.size() < vertices.size())
        colors.push_back(Color::white());
    
    if (colors.size() > vertices.size())
    {
        printf("Mesh colors (%d) has more values than vertices (%d).\n", GLsizei(colors.size()), GLsizei(vertices.size()));
        assert(false);
    }
}
