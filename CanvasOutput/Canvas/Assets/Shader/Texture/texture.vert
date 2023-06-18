#version 330

layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 normal;
//layout (location = 2) in vec4 tangent;
layout (location = 3) in vec4 color;
//layout (location = 4) in vec2 uv0;
//layout (location = 5) in vec2 uv1;
//layout (location = 6) in vec2 uv2;

struct Material {
    vec4 color;
    sampler2D mainTexture;
};

struct VertexOutput
{
    vec4 color;
    vec2 uv0;
};

uniform Material material;
out VertexOutput vo;

void main()
{
    vo.color = color;
    vo.uv0 = vec2(1,1);
    gl_Position = vec4(position.xyz, 1.0);
}