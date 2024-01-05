#version 450 core

in vec3 V_Normal;
in vec3 V_Pos;
in vec2 V_TexCoords;

out vec4 F_Color;


struct Material{
	float ShinyFactor;
	float DiffuseFactor;
	sampler2D TextureMap;
	sampler2D SpecularMap;
};

struct Light{
	vec3 LightColor;
	vec3 LightPos;
	vec3 LightDir;
	float Intensity;
	float Ambient;
	float AttenuationConstant;
	float AttenuationLinear;
	float AttenuationQuadratic;
};


struct PointLight{
	vec3 LightColor;
	vec3 LightPos;
	float Intensity;
	float AttenuationConstant;
	float AttenuationLinear;
	float AttenuationQuadratic;
};

struct DirLight{
	vec3 LightColor;
	vec3 LightDir;
	float Intensity;
	float Ambient;
};

uniform vec3 U_CameraPos;
uniform PointLight U_PointLight;
uniform DirLight U_DirLight;
uniform Material U_Object;

vec3 ProcessPointLight(PointLight light, Material material, vec3 camera, vec3 pos, vec3 normal, float specstren){
	vec3 L_Normal = normalize(normal);
	vec3 L_LightDir = normalize(light.LightPos - pos);
	float L_DiffuseFactor = max(dot(normal, L_LightDir), 0.0f) * material.DiffuseFactor;

	vec3 L_ViewDir = normalize(camera - pos);
	vec3 L_ReflectDir = reflect(-L_LightDir, normal);
	float L_Spec = pow(max(dot(L_ViewDir, L_ReflectDir), 0.0), material.ShinyFactor);
	vec3 L_SpecColor = texture(material.SpecularMap, V_TexCoords).rgb;
	float L_SpecStren = L_SpecColor.r + L_SpecColor.g + L_SpecColor.b;
	L_SpecStren /= 3;
	float L_SpecFactor = L_Spec * L_SpecStren;
	float L_Brightness = L_DiffuseFactor + L_SpecFactor;
	float L_Attenuation = light.Intensity;
	float L_Distance = distance(light.LightPos, pos);
	float L_Dimness = light.AttenuationConstant + (light.AttenuationLinear * L_Distance) + (light.AttenuationQuadratic * L_Distance * L_Distance);
	L_Attenuation /= L_Dimness;
	float L_FinalLightFactor = max(L_Brightness * L_Attenuation, 0.0f);
	vec3 L_RGBBrightness = light.LightColor * L_FinalLightFactor;
	return L_RGBBrightness;
}

vec3 ProcessDirLight(DirLight light, Material material, vec3 camera, vec3 pos, vec3 normal, float specstren){
	vec3 L_Normal = normalize(normal);
	vec3 L_LightDir = normalize(-light.LightDir);
	float L_DiffuseFactor = max(dot(normal, L_LightDir), 0.0f) * material.DiffuseFactor;

	vec3 L_ViewDir = normalize(camera - pos);
	vec3 L_ReflectDir = reflect(-L_LightDir, normal);
	float L_Spec = pow(max(dot(L_ViewDir, L_ReflectDir), 0.0), material.ShinyFactor);
	vec3 L_SpecColor = texture(material.SpecularMap, V_TexCoords).rgb;
	float L_SpecStren = L_SpecColor.r + L_SpecColor.g + L_SpecColor.b;
	L_SpecStren /= 3;
	float L_SpecFactor = L_Spec * L_SpecStren;
	float L_Brightness = L_DiffuseFactor;
	float L_FinalLightFactor = max(L_Brightness * light.Intensity, light.Ambient);
	vec3 L_RGBBrightness = light.LightColor * L_FinalLightFactor;
	return L_RGBBrightness;
}

void main(){

	
	vec3 L_SpecColor = texture(U_Object.SpecularMap, V_TexCoords).rgb;
	float L_SpecStren = L_SpecColor.r + L_SpecColor.g + L_SpecColor.b;
	L_SpecStren /= 3.0f;

	DirLight light = U_DirLight;
	light.LightColor = vec3(1.0f);
	light.LightDir = vec3(-0.2f, -1.0f, -0.3f);

	vec3 L_RGBBrightness = ProcessDirLight(light, U_Object, U_CameraPos, V_Pos, V_Normal, L_SpecStren);

	F_Color = texture(U_Object.TextureMap, V_TexCoords) * vec4(L_RGBBrightness, 1.0f);
	F_Color = vec4(normal * 0.5f + 0.5f, 1.0);
}