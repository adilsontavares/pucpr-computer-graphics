#version 400

in vec4 color;

uniform vec4 baseColor;
out vec4 outColor;

void main()
{
    outColor = vec4(
        color.r * baseColor.r,
        color.g * baseColor.g,
        color.b * baseColor.b,
        color.a * baseColor.a
    );
}
