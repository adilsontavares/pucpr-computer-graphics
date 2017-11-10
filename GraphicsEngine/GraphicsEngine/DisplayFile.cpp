//
//  DisplayFile.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 09/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "DisplayFile.hpp"
#include "File.hpp"
#include <cassert>
#include <fstream>
#include <rapidjson/document.h>

using namespace rapidjson;

DisplayFile::DisplayFile(const std::string& path)
{
    std::string contents = File::readAll(path);
    
    Document document;
    document.Parse(contents.c_str());
    
    assert(document.IsArray());
}
