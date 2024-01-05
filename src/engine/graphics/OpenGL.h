#ifndef OPENGL_H
#define OPENGL_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <time.h>
#include <sys/time.h>
#ifdef OPENGL_SOURCE
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#endif
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <GL/GL.h>
#include <GL/GLU.h>
#include <Windows.h>
#include <winternl.h>
#include <WinBase.h>
#include <conio.h>
#endif
#include "../../misc/Clock.h"

namespace OpenGL {

#define OPENGL_CONST const
#define CONST_ARG OPENGL_CONST GLuint 

	class OpenGLVertexArray;
	class OpenGLShaderProgram;
	class OpenGLTransform;
	class OpenGLInputHandler;

	struct DirectionalLight;

	typedef OpenGLVertexArray VertexArray;
	typedef OpenGLShaderProgram ShaderProgram;
	typedef OpenGLTransform Transform;
	typedef OpenGLInputHandler InputHandler;
	typedef glm::vec3 Vector3D;
	typedef glm::vec2 Vector2D;
	typedef glm::mat4 Matrix4x4;
	typedef GLFWwindow* Window;
	typedef FILE GLFile;

	CONST_ARG HEAP = 0;
	CONST_ARG STACK = 1;
	CONST_ARG OPENGL_TRUE = GL_TRUE;
	CONST_ARG OPENGL_FALSE = GL_FALSE;
	CONST_ARG GLSL = 2;
	CONST_ARG SPIR_V = 3;
	CONST_ARG ORTHROGRAPHIC_PROJECTION = 4;
	CONST_ARG ISOMETRIC_PROJECTION = 5;

	extern  GLvoid InitializeOpenGL(GLvoid);
	extern  GLvoid TerminateOpenGL(GLvoid);

	extern  GLboolean WindowOpenStatus(GLvoid);
	extern  GLvoid OpenWindow(GLint width, GLint height, const GLchar* title);
	extern  GLvoid DefaultColor(GLfloat* color);
	extern  GLvoid UpdateWindow(GLvoid);
	extern  GLvoid ResetWindow(GLvoid);
	extern  GLvoid CloseWindow(GLvoid);
	extern  GLvoid WindowFPS(GLfloat FramesPerSecond);
	extern  GLfloat DeltaTime(GLvoid);
	extern  GLfloat DeltaSeconds(GLvoid);
	extern  GLvoid TimerUnit(GLuint unit);
	extern  GLint TimerUnitSeconds(GLvoid);
	extern  Window WindowHandle(GLvoid);
	extern  GLvoid FullScreen(GLvoid);
	extern  GLvoid Windowed(GLvoid);

	extern  GLboolean PressedKey(GLint key);
	extern  Vector2D CursorCurrentPos(GLvoid);
	extern  Vector2D CursorDeltaPos(GLvoid);

	extern  GLvoid RenderBasicArray(GLint count);
	extern  GLvoid RenderElementArray(GLint count);

	extern  GLvoid ClearError(GLvoid);
	extern  GLvoid PrintError(GLvoid);

	extern  GLfloat RadianValue(GLfloat degrres);
	extern  GLvoid CameraFOV(GLfloat fov);
	extern  GLvoid CameraPlanes(GLfloat NEARPLANE, GLfloat FARPLANE);
	extern  GLvoid CameraProjectionMode(GLuint mode);
	extern  Matrix4x4 CreateProjectionMatrix(GLuint type, GLuint width, GLuint height);
	extern  Vector3D CameraDirection(GLvoid);
	extern  OpenGLTransform * CameraTransform(GLvoid);

	class OpenGLVertexArray {
	private:
		GLuint VAO = 0;
		GLuint VBO[16]{ 0 };
		GLuint EBO[16]{ 0 };
		GLuint TEX[16]{ 0 };
		GLboolean EBOMode = GL_FALSE;
		GLuint TextureUnit(GLint index);
	public:
		OpenGLVertexArray(GLint indexed);
		~OpenGLVertexArray(GLvoid);

		GLvoid BufferVertexDataArray(GLint index, GLsizei bytes, GLvoid* address);
		GLvoid BufferVertexIndexArray(GLint index, GLsizei bytes, GLvoid* address);
		GLvoid UseBuffer(GLint index);

		GLvoid RGBTexture(GLuint index, const GLchar* path);
		GLvoid UseTexture(GLint index);
	};

	class OpenGLShaderProgram {
	private:
		GLuint ShaderProgram = 0;
		GLuint ShaderLanguage = 0;
		GLuint UniformArray[64]{ 0 };
		GLuint TextureUnit[16]{ 0 };
		GLuint AttributeFormat[16]{ 0 };
		GLuint ProjectionMatrixIndex;
		GLuint ViewMatrixIndex;

		GLuint CompileGLSL(const GLchar* src, GLuint type);
		const GLchar* LoadShaderFile(const GLchar* path);
	public:
		OpenGLShaderProgram(GLint lang);
		~OpenGLShaderProgram(GLvoid);

		GLvoid CompileSourceCode(const GLchar* vs, const GLchar* fs);
		GLvoid CompileShaderFiles(const GLchar* vs, const GLchar* fs);

		GLvoid RunProgram(GLvoid);
		GLvoid RenderArrays(GLuint length);
		GLvoid AttributeSize(GLuint index, GLsizei size);

		GLvoid UniformLocation(GLint index, const GLchar* name);
		GLvoid UniformFloat(GLint index, GLfloat value);
		GLvoid UniformInteger(GLint index, GLint value);
		GLvoid UniformVector3D(GLint index, Vector3D vector);
		GLvoid UniformMatrix4x4(GLint index, Matrix4x4 matrix);
		GLvoid UniformTransform(GLint index, OpenGLTransform transform);
		GLvoid UniformDirectionalLight(const GLchar* name, DirectionalLight light);

		GLvoid ProjectionIndex(GLuint index);
		GLvoid ViewIndex(GLuint index);

		GLvoid TextureLocation(GLint index, const GLchar* name);
		GLvoid TextureUniform(GLint index);
	};

	class OpenGLTransform {
	private:
		Matrix4x4 Transform = Matrix4x4(1.0f);
		Vector3D ScaleVector = Vector3D(1.0f);
		Vector3D RotationVector = Vector3D(1.0f);
		Vector3D TranslationVector = Vector3D(0.0f);
	public:
		OpenGLTransform(Matrix4x4 transform);
		~OpenGLTransform(GLvoid);

		GLvoid Rotate(Vector3D RotationFactor);
		GLvoid Scale(Vector3D ScaleFactor);
		GLvoid Translate(Vector3D TranslateFactor);

		GLvoid SetRotate(Vector3D RotationFactor);
		GLvoid SetScale(Vector3D ScaleFactor);
		GLvoid SetTranslate(Vector3D TranslateFactor);

		Vector3D GetTranslation(GLvoid);
		Vector3D GetRotation(GLvoid);
		Vector3D GetScale(GLvoid);

		Matrix4x4 MatrixTransform(GLvoid);
	};

	struct DirectionalLight {
		Vector3D LightColor;
		Vector3D LightDir;
		float Intensity;
		float Ambient;
	};


}

#endif