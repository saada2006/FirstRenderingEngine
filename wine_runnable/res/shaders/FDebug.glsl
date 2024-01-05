#version 450 core

layout(location = 0) in vec3 V_Normal;
layout(location = 1) in vec3 V_Pos;
layout(location = 2) in vec2 V_TexCoords;

layout(location = 0) out vec4 F_Color;


struct Material{
	float ShinyFactor;
	float DiffuseFactor;
	sampler2D TextureMap;
	sampler2D SpecularMap;
};

struct Light{
	vec3 LightColor;
	vec3 LightPos;
	float Intensity;
	float Ambient;
	float AttenuationConstant;
	float AttenuationLinear;
	float AttenuationQuadratic;
};



uniform vec3 U_CameraPos;
uniform Light U_Light;
uniform Material U_Object;

void main(){
	vec4 L_TexColor = texture(U_Object.TextureMap, V_TexCoords);
	vec3 L_LightFactor = U_Light.LightColor;

	vec3 L_Normal = normalize(V_Normal);
	vec3 L_LightDir = normalize(U_Light.LightPos - V_Pos);
	float L_DiffuseFactor = max(dot(V_Normal, L_LightDir), 0.0f) * U_Object.DiffuseFactor;

	vec3 L_ViewDir = normalize(U_CameraPos - V_Pos);
	vec3 L_ReflectDir = reflect(-L_LightDir, V_Normal);
	float L_Spec = pow(max(dot(L_ViewDir, L_ReflectDir), 0.0), U_Object.ShinyFactor);
	vec3 L_SpecColor = texture(U_Object.SpecularMap, V_TexCoords).rgb;
	float L_SpecStren = L_SpecColor.r + L_SpecColor.g + L_SpecColor.b;
	L_SpecStren /= 3;
	float L_SpecFactor = L_Spec * L_SpecStren;
	float L_Brightness = L_DiffuseFactor + L_SpecFactor;
	float L_Attenuation = U_Light.Intensity;
	float L_Distance = distance(U_Light.LightPos, V_Pos);
	float L_Dimness = U_Light.AttenuationConstant + (U_Light.AttenuationLinear * L_Distance) + (U_Light.AttenuationQuadratic * L_Distance * L_Distance);
	L_Attenuation /= L_Dimness;
	float L_FinalLightFactor = max(L_Brightness * L_Attenuation, U_Light.Ambient);
	vec3 L_RGBBrightness = U_Light.LightColor * L_FinalLightFactor;

	F_Color = L_TexColor * vec4(L_RGBBrightness, 1.0f);
}