//GLOBALS

cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};


//TYPEDEFS
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL0;
};
    
struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
    float3 normal : NORMAL;
};


PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    
    //Change the position vector to be 4 units for the poroper matrix calcs
    input.position.w = 1.0f;
    
    //Calc position of vertex against the world, view and prokection
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
    output.tex = input.tex;
    
    //Calc the normal vector against the world matrix only
    output.normal = mul(input.normal, (float3x3) worldMatrix);
    
    //Normalize
    output.normal = normalize(output.normal);
    
    return output;
}
