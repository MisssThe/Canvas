#version 330

out vec4 FragColor;

struct Material {
    vec4 color;
};

struct VertexOutput
{
    vec4 color;
    vec2 uv0;
};

uniform Material material;
in VertexOutput vo;

void main()
{
    vec4 result = vec4(0,0,0,1);
    result.rgb = vo.color.rgb;
    FragColor = result;
}