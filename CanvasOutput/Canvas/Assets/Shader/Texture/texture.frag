#version 330

SHADER_MATERIAL_PROPERTY;

struct VertexOutput
{
    vec4 color;
    vec2 uv0;
};

in VertexOutput vo;
out vec4 FragColor;

void main()
{
    vec4 result = texture(material.mainTex, vo.uv0);
    result *= texture(material.maskTex, vo.uv0);
    result.rgb *= vo.color.rgb;
    FragColor = result;
}