//
//  Primitive.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 04/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Primitive.hpp"

Primitive::Primitive()
{
    reset();
}

void Primitive::generate()
{
}

void Primitive::reset()
{
    removeAllMeshes();
    generate();
    
    for (auto it = meshes.begin(); it != meshes.end(); ++it)
        it->assertConsistency();
}
