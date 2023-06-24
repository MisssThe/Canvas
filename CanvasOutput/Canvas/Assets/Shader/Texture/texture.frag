#version 330

SHADER_MATERIAL_PROPERTY material;

struct VertexOutput
{
    vec4 color;
    vec2 uv0;
};

in VertexOutput vo;
out vec4 FragColor;

void main()
{
    vec4 result = vec4(0,0,0,1);
    result.rgb = vo.color.rgb;
    FragColor = result;
}