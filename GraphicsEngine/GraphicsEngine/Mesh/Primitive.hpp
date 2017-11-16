//
//  Primitive.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Primitive_hpp
#define Primitive_hpp

#include "MeshNode.hpp"

class Primitive : public MeshNode
{
public:
    
    Primitive();
    
protected:
    
    void reset();
    virtual void generate();
};

#endif /* Primitive_hpp */
