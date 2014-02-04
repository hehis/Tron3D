#version 130

uniform float objectID;
out vec2 uv;

void mainDeform();

out float scaled_height;

void main(void)
{
	uv =  gl_MultiTexCoord0.xy;
	scaled_height = gl_Vertex.z;

	mainDeform();

	//gl_Position = gl_ModelViewProjectionMatrix  * gl_Vertex;
	return;

}