//
//  Camera.hpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 07/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Node.hpp"

class Camera: public Node
{
public:
    
    Camera();
    
    void lookAt(Vector3 point);
    
    virtual void update(GLfloat delta);
    virtual glm::mat4 getMatrix();
    
    void setFieldOfView(GLfloat fieldOfView);
    void setAspectRatio(GLfloat aspectRatio);
    void setNear(GLfloat near);
    void setFar(GLfloat far);
    
protected:
    
    GLfloat fieldOfView;
    GLfloat aspectRatio;
    GLfloat near;
    GLfloat far;
};

#endif /* Camera_hpp */
