//
//  ShaderArgument.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 09/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef ShaderArgument_hpp
#define ShaderArgument_hpp

#include <GL/glew.h>

class ShaderArgument
{
public:
    
    enum Type
    {
        FLOAT,
        VECTOR3,
        MATRIX4,
        COLOR
    };
    
    ShaderArgument(Type type, GLuint count);
    
    Type type;
    GLuint buffer;
    GLuint location;
    GLboolean isUniform;
    GLvoid *value;
    
    GLboolean isMatrix;
    GLboolean normalized;
    GLuint dataType;
    GLuint stepSize;
    GLuint bytes;
    GLuint count;
    
    void set();
    void load();
    
private:
    
    void setUniform();
    void setAttribute();
};

#endif /* ShaderArgument_hpp */
