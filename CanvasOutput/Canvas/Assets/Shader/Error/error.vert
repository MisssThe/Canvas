#version 330

layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 normal;
//layout (location = 2) in vec4 tangent;
//layout (location = 3) in vec4 color;
//layout (location = 4) in vec2 uv0;
//layout (location = 5) in vec2 uv1;
//layout (location = 6) in vec2 uv2;

SHADER_MATERIAL_PROPERTY material;

void main()
{
    gl_Position = vec4(position.xyz, 1.0);
}