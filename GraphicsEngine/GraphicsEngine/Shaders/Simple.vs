#version 400

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 vertexColor;

out vec4 color;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(position, 1);
    color = vertexColor;
}
