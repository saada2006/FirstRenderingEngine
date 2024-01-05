#include "src/engine/graphics/OpenGL.h"

#pragma warning(disable : 4996)

float vertices[] = {
        -0.5f,  0.5f, -0.5f, 0, 0,
        -0.5f, -0.5f, -0.5f, 0, 1,
         0.5f, -0.5f, -0.5f, 1, 1,
         0.5f,  0.5f, -0.5f, 1, 0,

        -0.5f,  0.5f,  0.5f, 0, 0,
        -0.5f, -0.5f,  0.5f, 0, 1,
         0.5f, -0.5f,  0.5f, 1, 1,
         0.5f,  0.5f,  0.5f, 1, 0,

         0.5f,  0.5f, -0.5f, 0, 0,
         0.5f, -0.5f, -0.5f, 0, 1,
         0.5f, -0.5f,  0.5f, 1, 1,
         0.5f,  0.5f,  0.5f, 1, 0,

        -0.5f,  0.5f, -0.5f, 0, 0,
        -0.5f, -0.5f, -0.5f, 0, 1,
        -0.5f, -0.5f,  0.5f, 1, 1,
        -0.5f,  0.5f,  0.5f, 1, 0,

        -0.5f,  0.5f,  0.5f, 0, 0,
        -0.5f,  0.5f, -0.5f, 0, 1,
         0.5f,  0.5f, -0.5f, 1, 1,
         0.5f,  0.5f,  0.5f, 1, 0,

        -0.5f, -0.5f,  0.5f, 0, 0,
        -0.5f, -0.5f, -0.5f, 0, 1,
         0.5f, -0.5f, -0.5f, 1, 1,
         0.5f, -0.5f,  0.5f, 1, 0,

};

float vertices2[] = {
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,

};

float vertices3[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
};

float vertices4[] = {
    -0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,   0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,     -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,     -1.0f,  0.0f,  0.0f,   1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,     -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,     -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,     -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,     -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
      
     0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,   1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,   1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,     0.0f, 1.0f,  0.0f,   0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,     0.0f, 1.0f,  0.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,     0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,     0.0f, 1.0f,  0.0f,   1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,     0.0f, 1.0f,  0.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,     0.0f, 1.0f,  0.0f,   0.0f, 1.0f
};

int indices2[]{
    0,  1,  2,
    3,  4,  5,
    6,  7,  8,
    9,  10, 11,
    12, 13, 14,
    15, 16, 17,
    18, 19, 20,
    21, 22, 23,
    24, 25, 26,
    27, 28, 29,
    30, 31, 32,
    33, 34, 35
};

int indices[] = {
        0,1,3,
        3,1,2,
        4,5,7,
        7,5,6,
        8,9,11,
        11,9,10,
        12,13,15,
        15,13,14,
        16,17,19,
        19,17,18,
        20,21,23,
        23,21,22

};

float data[] = {
     0.5,  0.5, 0,	1, 1,
     0.5, -0.5, 0,	1, 0,
    -0.5, -0.5, 0,	0, 0,
    -0.5,  0.5, 0,	0, 1,
};

unsigned int index_tri[] = {
    0, 1, 3,
    1, 2, 3
};

float light[] = {
     0.5,  0.5, 0,	
     0.5, -0.5, 0,
    -0.5, -0.5, 0,	
    -0.5,  0.5, 0,	
};

float color[] = {
    135.0f/256.0f, 206.0f/256.0f, 235.0f/256.0f, 1.0f
};

#define PLANE_SIZE 1000.0f
#define TEXTURE_SIZE 1000.0f

float floorData[] = {
     PLANE_SIZE,  0.0f,  PLANE_SIZE,     0.0f,  1.0f,  0.0f,      TEXTURE_SIZE,  TEXTURE_SIZE,
     PLANE_SIZE,  0.0f, -PLANE_SIZE,     0.0f,  1.0f,  0.0f,      TEXTURE_SIZE, -TEXTURE_SIZE,
    -PLANE_SIZE,  0.0f, -PLANE_SIZE,     0.0f,  1.0f,  0.0f,     -TEXTURE_SIZE, -TEXTURE_SIZE,
    -PLANE_SIZE,  0.0f,  PLANE_SIZE,     0.0f,  1.0f,  0.0f,     -TEXTURE_SIZE,  TEXTURE_SIZE,
};

unsigned int index2[]{
        0,1,3,
        3,1,2,
};

const char* VertexShader = "res/shaders/VDebug.glsl";
const char* FragmentShader = "res/shaders/FDebug.glsl";
const char* UniformName = "U_Color";
const char* DiffusePath = "res/textures/container_diff.png";
const char* SpecularPath = "res/textures/container_spec.png";
const char* FloorPath = "res/textures/wall_diff.png";
const char* FloorSpec = "res/textures/Cube.png";

int main() {
    printf("This is a Microsoft Windows only program.\nFly around with the keys W and S (A and D don't work).\nTo look around, move your mouse\nTo close the window, press ALT+F4 at the same time\n");
    
    bool isFullscreen = false;
    OpenGL::DefaultColor(color);
    OpenGL::CameraProjectionMode(OpenGL::ISOMETRIC_PROJECTION);
    OpenGL::CameraFOV(OpenGL::RadianValue(45.0f));
    OpenGL::WindowFPS(144.0f);
    OpenGL::OpenWindow(1280, 720, "OpenGL");
    OpenGL::VertexArray Object0 = OpenGL::VertexArray(OpenGL::OPENGL_TRUE);
    Object0.BufferVertexDataArray(0, sizeof(vertices4), vertices4);
    Object0.BufferVertexIndexArray(0, sizeof(indices2), indices2);
    Object0.UseBuffer(0);
    Object0.RGBTexture(0, DiffusePath);
    Object0.RGBTexture(1, SpecularPath);
    OpenGL::ShaderProgram Shader0 = OpenGL::ShaderProgram(OpenGL::GLSL);
    Shader0.CompileShaderFiles(VertexShader, FragmentShader);
    VertexShader = "res/shaders/VLight.glsl";
    FragmentShader = "res/shaders/FLight.glsl";
    Shader0.AttributeSize(0, 12);
    Shader0.AttributeSize(1, 12);
    Shader0.AttributeSize(2, 8);
    Shader0.TextureLocation(0, "U_Object.TextureMap");
    Shader0.TextureLocation(1, "U_Object.SpecularMap");
    Shader0.UniformLocation(0, "U_ModelMatrix");
    Shader0.UniformLocation(1, "U_ViewMatrix");
    Shader0.UniformLocation(2, "U_ProjectionMatrix");
    Shader0.UniformLocation(3, "U_Light.LightColor");
    Shader0.UniformLocation(4, "U_Light.Ambient");
    Shader0.UniformLocation(5, "U_Light.LightPos");
    Shader0.UniformLocation(6, "U_CameraPos");
    Shader0.UniformLocation(7, "U_Object.SpecStrn");
    Shader0.UniformLocation(8, "U_Object.ShinyFactor");
    Shader0.UniformLocation(9, "U_Light.AttenuationConstant");
    Shader0.UniformLocation(10, "U_Light.AttenuationLinear");
    Shader0.UniformLocation(11, "U_Light.AttenuationQuadratic");
    Shader0.UniformLocation(12, "U_Light.Intensity");
    Shader0.UniformLocation(13, "U_Object.DiffuseFactor");
    Shader0.UniformLocation(14, "U_Light.Intensity.LightDir");
    Shader0.ViewIndex(1);
    Shader0.ProjectionIndex(2);
    OpenGL::Transform Transform0 = OpenGL::Transform(OpenGL::Matrix4x4(1.0f));
    Transform0.Translate(OpenGL::Vector3D(0.0f, 0.0f, -10.0f));
    OpenGL::UpdateWindow();
    Transform0.Scale(OpenGL::Vector3D(0.0f));
    OpenGL::Transform* CameraPointer = OpenGL::CameraTransform();
    CameraPointer->Rotate(OpenGL::Vector3D(0.25f, 0.0f, 0.0f));
    Transform0.SetTranslate(OpenGL::Vector3D(0.0f, 0.5f, 10.0f));
    OpenGL::ShaderProgram Shader1 = OpenGL::ShaderProgram(OpenGL::GLSL);
    Shader1.CompileShaderFiles(VertexShader, FragmentShader);
    Shader1.AttributeSize(0, 12);
    Shader1.UniformLocation(0, "U_ModelMatrix");
    Shader1.UniformLocation(1, "U_ViewMatrix");
    Shader1.UniformLocation(2, "U_ProjectionMatrix");
    Shader1.UniformLocation(3, "U_LightColor");
    Shader1.ViewIndex(1);
    Shader1.ProjectionIndex(2);
    OpenGL::Transform Transform1 = OpenGL::Transform(OpenGL::Matrix4x4(1.0f));
    Transform1.Translate(OpenGL::Vector3D(5.5f, 5.0f, 17.5f));
    OpenGL::VertexArray Object1 = OpenGL::VertexArray(OpenGL::OPENGL_TRUE);
    Object1.BufferVertexDataArray(0, sizeof(vertices2), vertices2);
    Object1.BufferVertexIndexArray(0, sizeof(indices), indices);
    OpenGL::VertexArray Object2 = OpenGL::VertexArray(OpenGL::OPENGL_TRUE);
    Object2.BufferVertexDataArray(0, sizeof(floorData), floorData);
    Object2.BufferVertexIndexArray(0, sizeof(index_tri), index_tri);
    Object2.RGBTexture(0, FloorPath);
    Object2.RGBTexture(1, FloorSpec);
    OpenGL::Transform Transform2 = OpenGL::Transform(OpenGL::Matrix4x4(1.0f));
    Transform2.Translate(OpenGL::Vector3D(0.0f));
    CameraPointer->Translate(OpenGL::Vector3D(0.0f, 1.5f, 0.0f));

    OpenGL::DirectionalLight light0 = OpenGL::DirectionalLight{ OpenGL::Vector3D(1.0f), OpenGL::Vector3D(-0.2f, -1.0f, -0.3f), 2.0f, 0.1f };

    while (OpenGL::WindowOpenStatus()) {
        float glfwTime = glfwGetTime();
        OpenGL::Vector3D LightColor = OpenGL::Vector3D(1.0f);
        Transform0.SetRotate(OpenGL::Vector3D(0.0f, glfwGetTime() * 0.1f, 0.0f));
        auto start = time(MICROSECOND);
        OpenGL::ResetWindow();
        const float CAMERA_SPEED = 100.0f;
        OpenGL::Vector3D Displacement(0.0f);
        if (OpenGL::PressedKey(GLFW_KEY_W)) {
            Displacement -= OpenGL::CameraDirection() * OpenGL::DeltaSeconds() * CAMERA_SPEED;
        }
        if (OpenGL::PressedKey(GLFW_KEY_S)) {
            Displacement += OpenGL::CameraDirection() * OpenGL::DeltaSeconds() * CAMERA_SPEED;
        }
        CameraPointer->Translate(Displacement);
        const float sens = 0.0001f;
        CameraPointer->Rotate(OpenGL::Vector3D(OpenGL::CursorDeltaPos().x * sens, OpenGL::CursorDeltaPos().y * sens, 0.0f));
        
        Object0.UseBuffer(0);
        Shader0.RunProgram();
        Shader0.UniformVector3D(6, CameraPointer->GetTranslation());
        Shader0.UniformDirectionalLight("U_DirLight", light0);

        Object0.UseTexture(0);
        Object0.UseTexture(1);
        Shader0.TextureUniform(0);
        Shader0.UniformTransform(0, Transform0);
        Shader0.RenderArrays(36);

        Shader0.RunProgram();
        Object2.UseBuffer(0);
        Shader0.UniformTransform(0, Transform2);
        Shader0.UniformDirectionalLight("U_DirLight", light0);

        Object2.UseTexture(0);
        Object2.UseTexture(1);
        Shader0.RenderArrays(6);
        Object1.UseBuffer(0);
        Shader1.RunProgram();
        Shader1.UniformTransform(0, Transform1);
        Shader1.UniformVector3D(3, LightColor);
        Shader1.RenderArrays(36);
        OpenGL::UpdateWindow();
        OpenGL::PrintError();

        if (OpenGL::PressedKey(GLFW_KEY_F11)) {
            if (isFullscreen) {
                OpenGL::Windowed();
                isFullscreen = false;
            }
            else {
                OpenGL::FullScreen();
                isFullscreen = true;  
            }
        }
        auto end = time(MICROSECOND);
        auto delta = end - start;
        float time = MICROSECOND;
        time /= delta;
        printf("FPS:\t%f\n", time);

    }
    OpenGL::CloseWindow();
}