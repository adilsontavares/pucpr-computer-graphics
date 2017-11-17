//
//  File.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 03/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef File_h
#define File_h

#include <fstream>
#include <cassert>

class File
{
public:
    
    static std::string readAll(const std::string& path)
    {
        std::ifstream file(path);
        assert(file.is_open());
        
        std::string content;
        
        file.seekg(0, std::ios::end);
        content.reserve(file.tellg());
        file.seekg(0, std::ios::beg);
        
        content.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        
        return content;
    }
};

#endif /* File_h */
