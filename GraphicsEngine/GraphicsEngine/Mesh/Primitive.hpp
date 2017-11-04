//
//  Primitive.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Primitive_hpp
#define Primitive_hpp

#include "Mesh.hpp"

class Primitive : public Mesh
{
public:
    
    Primitive();
    
protected:
    
    virtual void resetMesh() = 0;
};

#endif /* Primitive_hpp */
