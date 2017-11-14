//
//  DisplayFile.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 09/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef DisplayFile_hpp
#define DisplayFile_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "DisplayFileObject.hpp"

class DisplayFile
{
private:
    
    std::vector<DisplayFileObject*> objects;
    std::string path;
    
public:
    
    DisplayFile(const std::string& path);
    
    std::vector<DisplayFileObject*> getObjects();
};

#endif /* DisplayFile_hpp */
