//
//  DisplayFileObject.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 14/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "DisplayFileObject.hpp"
#include "MeshNode.hpp"
#include "Primitives2D.h"
#include "Primitives3D.h"
#include "Camera.hpp"

#include <map>
#include <cassert>
#include <regex>

DisplayFileObject::DisplayFileObject(const rapidjson::Value& value) : value(value)
{
}

DisplayFileObject::Type DisplayFileObject::getType()
{
    std::map<std::string, DisplayFileObject::Type> map;
    map["rectangle"] = DisplayFileObject::Type::RECTANGLE;
    map["square"] = DisplayFileObject::Type::SQUARE;
    map["circle"] = DisplayFileObject::Type::CIRCLE;
    map["triangle"] = DisplayFileObject::Type::TRIANGLE;
    map["line"] = DisplayFileObject::Type::LINE;
    map["point"] = DisplayFileObject::Type::POINT;
    map["box"] = DisplayFileObject::Type::BOX;
    map["cube"] = DisplayFileObject::Type::CUBE;
    map["cylinder"] = DisplayFileObject::Type::CYLINDER;
    map["sphere"] = DisplayFileObject::Type::SPHERE;
    map["cone"] = DisplayFileObject::Type::CONE;
    map["camera"] = DisplayFileObject::Type::CAMERA;
    
    const char *arg = value["type"].GetString();
    auto it = map.find(arg);
    
    if (it == map.end())
        return DisplayFileObject::Type::UNKNOWN;
    
    return it->second;
}

Node *DisplayFileObject::instantiate()
{
    Node *node = 0;
    
    switch (getType())
    {
//        case CAMERA: return new Camera(this);
//
//        case RECTANGLE: return createMeshNode(new Rectangle(this));
//        case SQUARE: return createMeshNode(new Square(this));
//        case CIRCLE: return createMeshNode(new Circle(this));
//        case TRIANGLE: return createMeshNode(new Triangle(this));
//
        case BOX:
            node = Box::create(this);
            break;
            
        case CUBE:
            node = Cube::create(this);
            break;
            
        case CYLINDER:
            node = Cylinder::create(this);
            break;
            
        case SPHERE:
            node = Sphere::create(this);
            break;
//        case CONE: return createMeshNode(new Cone(this));
//
//        case LINE: return new LineNode(this);
//        case POINT: return new PointNode(this);
            
        default:
            assert(false);
            break;
    }
    
    assert(node);
    node->loadConfig(this);
    
    return node;
}

GLboolean DisplayFileObject::hasProperty(const char *path)
{
    return value.HasMember(path);
}

GLint DisplayFileObject::getInt(const char *path)
{
    return value[path].GetInt();
}

GLfloat DisplayFileObject::getFloat(const char *path)
{
    return value[path].GetFloat();
}

Vector3 DisplayFileObject::getVector3(const char *path)
{
    auto str = std::string(value.FindMember(path)->value.GetString());
    return Vector3(str.c_str());
}

Color DisplayFileObject::getColor(const char *path)
{
    const char *hex = value[path].GetString();
    return Color(hex);
}

GLboolean DisplayFileObject::getBool(const char *path)
{
    return value[path].GetBool();
}

void DisplayFileObject::assertInt(const char *path)
{
    assert(value.HasMember(path) && value[path].IsInt());
}

void DisplayFileObject::assertFloat(const char *path)
{
    assert(value.HasMember(path) && (value[path].IsInt() || value[path].IsFloat()));
}

void DisplayFileObject::assertColor(const char *path)
{
    assert(value.HasMember(path) && value[path].IsString());
}

void DisplayFileObject::assertBool(const char *path)
{
    assert(value.HasMember(path) && value[path].IsBool());
}

void DisplayFileObject::assertVector3(const char *path)
{
    assert(value.HasMember(path) && value[path].IsString());
}
