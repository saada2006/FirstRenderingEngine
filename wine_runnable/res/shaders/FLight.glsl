#version 450 core

layout(location = 0) out vec3 F_Color;

uniform vec3 U_LightColor;

void main(){
	F_Color = U_LightColor;
}