#version 130

uniform float objectID;
uniform bool isReflecting;
out vec2 uv;

void mainDeform();
void mainDeformReflected();

out float scaled_height;

void main(void)
{
	uv =  gl_MultiTexCoord0.xy;
	scaled_height = gl_Vertex.z;


	if (isReflecting) {
		mainDeformReflected();//gl_Position = gl_ModelViewProjectionMatrix  * gl_Vertex;
	} else {
		mainDeform();
	}


	return;

}