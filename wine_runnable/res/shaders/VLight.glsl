#version 450 core

layout(location = 0) in vec3 A_Pos;

uniform mat4 U_ModelMatrix;
uniform mat4 U_ViewMatrix;
uniform mat4 U_ProjectionMatrix;

void main(){
	gl_Position = U_ProjectionMatrix * U_ViewMatrix * U_ModelMatrix * vec4(A_Pos, 1.0f);
}