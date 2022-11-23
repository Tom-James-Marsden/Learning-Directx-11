//GLOBALS
Texture2D shaderTexture;
SamplerState SampletType;

cbuffer LightBuffer
{
    float4 diffuseColor;
    float3 lightDirection;
    float padding;
};


//TYPEDEFS
struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
};


float4 LightPixelShader(PixelInputType input) : SV_TARGET
{
    float4 textureColor;
    float3 lightDir;
    float lightIntensity;
    float4 color;
    
    
    //Sample tex
    textureColor = shaderTexture.Sample(SampletType, input.tex);
    
    //Invert the light direction for calcs
    lightDir = -lightDirection;
    
    //Calculate the amount of light on this pixel
    lightIntensity = saturate(dot(input.normal, lightDir));
    
    //Determine the final amount of diffuse color based on the diffuse color combined with the light intensity
    color = saturate(diffuseColor * lightIntensity);
    
    //Multiply the texture pixel and the final diffuse color to get the finalpixel color result
    color = color * textureColor;
    
    return color;
}