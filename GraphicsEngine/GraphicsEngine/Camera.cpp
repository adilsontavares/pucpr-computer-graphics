//
//  Camera.cpp
//  GraphicsEngine
//
//  Created by Adilson Tavares on 07/11/2017.
//  Copyright © 2017 Adilson Tavares. All rights reserved.
//

#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
    fieldOfView = 60;
    aspectRatio = 1;
    near = 0.1;
    far = 1000;
}

void Camera::setFieldOfView(GLfloat fieldOfView)
{
    this->fieldOfView = fieldOfView;
}

void Camera::setAspectRatio(GLfloat aspectRatio)
{
    this->aspectRatio = aspectRatio;
}

void Camera::setNear(GLfloat near)
{
    this->near = near;
}

void Camera::setFar(GLfloat far)
{
    this->far = far;
}

void Camera::update(GLfloat delta)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    auto matrix = getMatrix();
    glLoadMatrixf(&matrix[0][0]);
    
    glMatrixMode(GL_MODELVIEW);
}

glm::mat4 Camera::getMatrix()
{
    auto pos = glm::vec3(position.x, position.y, position.z);
    auto up = glm::vec3(0, 1, 0);
    
    glm::mat4 centerMat = glm::mat4(1);
    centerMat = glm::rotate(centerMat, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    centerMat = glm::rotate(centerMat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    centerMat = glm::rotate(centerMat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    
    auto center = centerMat * glm::vec4(0, 0, 10, 1);
    
    return glm::perspective(glm::radians(fieldOfView), aspectRatio, near, far) * glm::lookAt(pos, glm::vec3(center), up);
}

void Camera::lookAt(Vector3 point)
{
    const auto delta = (point - position);

    auto rotx = atan2(delta.y, delta.z);
    auto roty = atan2(delta.x * cos(rotx), delta.z);
    auto rotz = atan2(cos(rotx), sin(rotx) * sin(roty));

    auto rot = Vector3(rotx, roty, rotz);
    rotation = rot.rad2deg();
}
