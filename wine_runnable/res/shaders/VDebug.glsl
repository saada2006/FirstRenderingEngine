#version 450 core

layout(location = 0) in vec3 A_Pos;
layout(location = 1) in vec3 A_Normal;
layout(location = 2) in vec2 A_TexCoords;

out vec3 V_Normal;
out vec3 V_Pos;
out vec2 V_TexCoords;

uniform mat4 U_ModelMatrix;
uniform mat4 U_ViewMatrix;
uniform mat4 U_ProjectionMatrix;

void main(){
	gl_Position = U_ProjectionMatrix * U_ViewMatrix * U_ModelMatrix * vec4(A_Pos, 1.0f);
	V_Normal = (U_ModelMatrix * vec4(A_Normal, 0.0f)).xyz;
	V_Pos = (U_ModelMatrix * vec4(A_Pos, 1.0f)).xyz;
	V_TexCoords = A_TexCoords;
}