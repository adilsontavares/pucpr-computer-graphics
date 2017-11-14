//
//  Mesh.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Mesh.hpp"
#include <cassert>

Mesh::Mesh()
{
    name = "unnamed";
    drawMode = GL_TRIANGLES;
    dirty = false;
    
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);
    glGenBuffers(1, &colorBuffer);
}

void Mesh::updateBuffers(ShaderProgram *program)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(vertices[0]), vertices.data(), GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faces.size() * sizeof(faces[0]), faces.data(), GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(colors[0]), colors.data(), GL_DYNAMIC_DRAW);
    
    program->setAttribute("position", &vertices[0], GLuint(vertices.size()), ShaderArgument::Type::VECTOR3);
    program->setAttribute("vertexColor", &colors[0], GLuint(colors.size()), ShaderArgument::Type::COLOR);
}

void Mesh::render()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glDrawElements(drawMode, GLsizei(faces.size()), GL_UNSIGNED_INT, 0);
}

void Mesh::setName(const std::string &name)
{
    this->name = name;
}

std::string Mesh::getName()
{
    return name;
}

void Mesh::setVertices(Vector3 *vertices, GLuint count)
{
    this->vertices.clear();
    
    for (GLuint i = 0; i < count; ++i)
        this->vertices.push_back(vertices[i]);
    
    dirty = true;
}

void Mesh::setDrawMode(GLuint mode)
{
    drawMode = mode;
}

GLuint Mesh::getDrawMode()
{
    return drawMode;
}

void Mesh::setFaces(GLuint *faces, GLuint count)
{
    this->faces.clear();
    
    for (GLuint i = 0; i < count; ++i)
        this->faces.push_back(faces[i]);
    
    dirty = true;
}

void Mesh::setColors(Color *colors, GLuint count)
{
    this->colors.clear();
    
    for (GLuint i = 0; i < count; ++i)
        this->colors.push_back(colors[i]);
    
    dirty = true;
}

void Mesh::clear()
{
    vertices.clear();
    faces.clear();
    colors.clear();
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

GLboolean Mesh::isDirty()
{
    return dirty;
}

void Mesh::setDirty(GLboolean dirty)
{
    this->dirty = dirty;
}

GLuint Mesh::loopVertexIndex(GLuint index)
{
    return index % vertices.size();
}
