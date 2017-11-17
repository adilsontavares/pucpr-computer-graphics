//
//  LineNode.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 07/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef LineNode_hpp
#define LineNode_hpp

#include "RenderNode.hpp"
#include "Color.hpp"

class LineNode: public RenderNode
{
public:
    
    LineNode(Vector3 origin, Vector3 destin);
    
    virtual void draw(glm::mat4 base);
    
    void setOrigin(Vector3 origin);
    void setDestination(Vector3 destin);
    void setOriginColor(Color color);
    void setDestinationColor(Color color);
    
    Vector3 getOrigin();
    Vector3 getDestination();
    Color getOriginColor();
    Color getDestinationColor();
    
protected:
    
    void updateVertexBuffer();
    void updateColorBuffer();
    
    GLuint vertexBuffer;
    GLuint colorBuffer;
    GLuint arrayId;
    
    Vector3 origin;
    Vector3 destin;
    
    Color originColor;
    Color destinColor;
};

#endif /* LineNode_hpp */
