#version 330

out vec4 FragColor;

SHADER_MATERIAL_PROPERTY material;

struct VertexOutput
{
    vec4 color;
    vec2 uv0;
};

in VertexOutput vo;

void main()
{
    vec4 result = vec4(0,0,0,1);
    result.rgb = vo.color.rgb;
    FragColor = result;
}