

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
};


struct PixelInputType
{
    float4 position : SV_Position;
    float2 tex : TEXCOORD0;
};


PixelInputType TextureVertexShader(VertexInputType input)
{
    PixelInputType output;
    
    //change the position vector to be 4 units for proper matrix calcs
    input.position.w = 1.0f;
    
    //Calc the pos of the vertex against the world view and projection matrix
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
    output.tex = input.tex;

    return output;
}