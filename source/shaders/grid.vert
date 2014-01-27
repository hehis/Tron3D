#version 130

uniform int levelSize;
uniform float objectID;
uniform vec2 nearFar;

out vec2 uv;

void main()
{
	uv = (gl_Vertex).xy / levelSize + vec2(0.5, 0.5);
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex ;
}