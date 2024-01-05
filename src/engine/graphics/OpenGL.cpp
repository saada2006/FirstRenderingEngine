#define OPENGL_SOURCE
#include "OpenGL.h"

#include <iostream>

namespace OpenGL {

	Matrix4x4 ProjectionMatrix = glm::mat4(1.0f);
	GLuint ProjectionMode = ISOMETRIC_PROJECTION;
	GLfloat FOV;
	GLfloat NearPlane = 0.1f;
	GLfloat FarPlane = 100000.0f;
	Matrix4x4 ViewMatrix = glm::mat4(1.0f);
	Vector3D CameraDir = Vector3D(0.0f);
	OpenGLTransform ViewCameraTransform = OpenGLTransform(Matrix4x4(1.0f));

	GLuint FramebufferWidth;
	GLuint FramebufferHeight;

	GLuint WindowHeight;
	GLuint WindowWidth;

	GLuint OPENGL_TIME_UNIT = MICROSECOND;
	GLfloat FPS = 1;
	GLint64 Start;
	GLint64 DTimeStart, DTimeEnd, DTime;
	const GLchar* WindowTitle;

	GLdouble CursorXPos;
	GLdouble CursorYPos;
	GLdouble DeltaXPos;
	GLdouble DeltaYPos;
	GLuint FrameCounter = 0;
	GLuint MouseUpdates = 0;

	 GLchar* CombineStrings(const GLchar* str0, const GLchar* str1) {
		GLsizei str0size = strlen(str0);
		GLsizei str1size = strlen(str1);
		GLchar* str = new GLchar[str0size + str1size + 1]{ '\0' };
		memcpy(str, str0, str0size);
		memcpy(str + str0size, str1, str1size);
		return str;
	}

	GLvoid MousePosHandler(Window win, GLdouble xpos, GLdouble ypos) {
		return;
		DeltaXPos = xpos - CursorXPos;
		DeltaYPos = CursorYPos - ypos;
		CursorXPos = xpos;
		CursorYPos = ypos;
		MouseUpdates++;
	}

	 Vector2D CursorCurrentPos(GLvoid) {
		return Vector2D(CursorXPos, CursorYPos);
	}

	 Vector2D CursorDeltaPos(GLvoid) {
		Vector2D vector = Vector2D(DeltaXPos, DeltaYPos);
		return vector;
	}

	 GLvoid OpenGLConsole(const GLchar* line) {
		printf("%s%s%c", "[OpenGL] ", line, '\n');
	}

	 GLvoid UserConsole(const GLchar* line) {
		std::cout << line << '\n';
	}

	 GLvoid InitializeOpenGL(GLvoid) {
		glewInit();
		stbi_set_flip_vertically_on_load(true);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}

	 GLvoid TerminateOpenGL(GLvoid) {

	}

	GLFWwindow* OpenGLWindow;
	GLfloat* CLEAR_COLOR = new GLfloat[4]{ 0.0f, 0.0f, 0.0f, 1.0f };

	 GLvoid FramebufferResize(GLFWwindow* window, GLint width, GLint height) {
		glViewport(0, 0, width, height);
		CreateProjectionMatrix(ProjectionMode, width, height);
		FramebufferWidth = width;
		FramebufferHeight = height;

	}

	 GLvoid OpenWindow(GLint width, GLint height, const GLchar* title) {
		if (glfwInit() == GLFW_FALSE) {
			OpenGLConsole("Unable to start GLFW!");
		}
		OpenGLWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
		glfwMakeContextCurrent(OpenGLWindow);
		glfwSwapInterval(0);
		glfwSetWindowPos(OpenGLWindow, 0, 30);
		glfwSetFramebufferSizeCallback(OpenGLWindow, FramebufferResize);
		InitializeOpenGL();
		DTimeStart = time(OPENGL_TIME_UNIT);
		CreateProjectionMatrix(ProjectionMode, width, height);
		FramebufferWidth = width;
		FramebufferHeight = height;
		glfwSetInputMode(OpenGLWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwGetCursorPos(OpenGLWindow, &CursorXPos, &CursorYPos);
		WindowTitle = title;
		WindowWidth = width;
		WindowHeight = height;
		glEnable(GL_DEPTH_TEST);
		//glfwSetWindowSizeCallback(OpenGLWindow, WindowResize);
	}

	 GLvoid FullScreen(GLvoid) {
		GLFWmonitor* Monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* MonitorMode = glfwGetVideoMode(Monitor);

		/*
		glfwWindowHint(GLFW_RED_BITS, MonitorMode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, MonitorMode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, MonitorMode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, MonitorMode->refreshRate);
		*/

		//OpenGLWindow = glfwCreateWindow(MonitorMode->width, MonitorMode->height, WindowTitle, Monitor, nullptr);

		glfwSetWindowMonitor(OpenGLWindow, Monitor, 100, 100, MonitorMode->width, MonitorMode->height, MonitorMode->refreshRate);
		//glViewport(0, 0, MonitorMode->width, MonitorMode->height);
	}

	 GLvoid Windowed(GLvoid) {
		glfwSetWindowMonitor(OpenGLWindow, nullptr, 0, 0, WindowWidth, WindowHeight, FPS);
		glfwSetWindowPos(OpenGLWindow, 0, 30);
	}

	 GLboolean WindowOpenStatus(GLvoid) {
		return !glfwWindowShouldClose(OpenGLWindow);
		
	}

	 GLvoid UpdateWindow(GLvoid) {
		GLfloat frameTime = OPENGL_TIME_UNIT;
		frameTime /= FPS;
		GLfloat waitTime = time(OPENGL_TIME_UNIT) - Start;
		waitTime = frameTime - waitTime;
		stop(waitTime, OPENGL_TIME_UNIT);
		glfwSwapBuffers(OpenGLWindow);
		glfwPollEvents();
		DTimeEnd = time(OPENGL_TIME_UNIT);
		CreateProjectionMatrix(ProjectionMode, FramebufferWidth, FramebufferHeight);
		FrameCounter++;
		GLdouble xpos, ypos;
		glfwGetCursorPos(OpenGLWindow, &xpos, &ypos);
		DeltaXPos = xpos - CursorXPos;
		DeltaYPos = CursorYPos - ypos;
		CursorXPos = xpos;
		CursorYPos = ypos;
	}

	 GLvoid DefaultColor(GLfloat* color) {
		CLEAR_COLOR = color;
	}

	 GLvoid ResetWindow(GLvoid) {
		Start = time(OPENGL_TIME_UNIT);
		const GLfloat DefaultDepth = 0.0f;
		glClearBufferfv(GL_COLOR, 0, CLEAR_COLOR);
		glClearBufferfv(GL_DEPTH, 0, &DefaultDepth);
		glClear(GL_DEPTH_BUFFER_BIT);
		DTimeStart = time(OPENGL_TIME_UNIT);
	}

	 GLvoid CloseWindow(GLvoid) {
		glfwDestroyWindow(OpenGLWindow);
		glfwTerminate();
		TerminateOpenGL();
	}

	 GLvoid WindowFPS(GLfloat FramesPerSecond) {
		FPS = FramesPerSecond;
	}

	 GLvoid RenderBasicArray(GLint count) {
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, count, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, count);
		glDisableVertexAttribArray(0);
	}

	 GLvoid RenderElementArray(GLint count) {
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, count, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
		glDisableVertexAttribArray(0);
	}

	 GLvoid ClearError(GLvoid) {
		while (glGetError() != GL_NO_ERROR) {}
	}

	 GLvoid PrintError(GLvoid) {
		bool ErrorStatus = true;
		while (ErrorStatus) {
			GLenum error = glGetError();
			switch (error)
			{
			case GL_INVALID_ENUM:
				OpenGLConsole("GL_INVALID_ENUM");
				break;
			case GL_INVALID_VALUE:
				OpenGLConsole("GL_INVALID_VALUE");
				break;
			case GL_INVALID_OPERATION:
				OpenGLConsole("GL_INVALID_OPERATION");
				break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:
				OpenGLConsole("GL_INVALID_FRAMEBUFFER_OPERATION");
				break;
			case GL_OUT_OF_MEMORY:
				OpenGLConsole("GL_OUT_OF_MEMORY");
				break;
			case GL_STACK_OVERFLOW:
				OpenGLConsole("GL_STACK_OVERFLOW");
				break;
			case GL_STACK_UNDERFLOW:
				OpenGLConsole("GL_STACK_OVERFLOW");
				break;
			case GL_NO_ERROR:
			default:
				ErrorStatus = false;
				break;
			}
		}
	}

	 GLfloat RadianValue(GLfloat degrees) {
		return glm::radians(degrees);
	}

	 GLfloat DeltaTime(GLvoid) {
		DTime = DTimeEnd - DTimeStart;
		return DTime;
	}

	 GLvoid TimerUnit(GLuint unit) {
		OPENGL_TIME_UNIT = unit;
	}

	  GLint TimerUnitSeconds(GLvoid) {
		return OPENGL_TIME_UNIT;
	}

	 GLfloat DeltaSeconds(GLvoid) {
		GLfloat Unit = TimerUnitSeconds();
		return DeltaTime() / Unit;
	}

	 Matrix4x4 CreateProjectionMatrix(GLuint type, GLuint width, GLuint height) {
		if (type == ORTHROGRAPHIC_PROJECTION) {
			ProjectionMatrix == glm::ortho(0.0f, (GLfloat)width, 0.0f, (GLfloat)height, NearPlane, FarPlane);
		}
		else if (type == ISOMETRIC_PROJECTION) {
			ProjectionMatrix == glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
		}
		else {
			ProjectionMatrix = glm::mat4(1.0f);
		}
		ProjectionMatrix == glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
		return ProjectionMatrix;
	}

	 GLvoid CameraFOV(GLfloat fov) {
		FOV = fov;
	}

	 GLvoid CameraPlanes(GLfloat NEARPLANE, GLfloat FARPLANE) {
		NearPlane = NEARPLANE;
		FarPlane = FARPLANE;
	}

	 GLvoid CameraProjectionMode(GLuint mode) {
		ProjectionMode = mode;
	}

	 Vector3D CameraDirection(GLvoid) {
		return CameraDir;
	}

	 OpenGLTransform * CameraTransform(GLvoid) {
		return &ViewCameraTransform;
	}

	 GLvoid KeyboardHandler(GLFWkeyfun keyboard) {
		glfwSetKeyCallback(OpenGLWindow, keyboard);
	}

	 GLvoid MouseHandler(GLFWmousebuttonfun button, GLFWscrollfun scroll, GLFWcursorposfun pos) {
		glfwSetMouseButtonCallback(OpenGLWindow, button);
		glfwSetScrollCallback(OpenGLWindow, scroll);
		glfwSetCursorPosCallback(OpenGLWindow, pos);
	}

	 Window WindowHandle(GLvoid) {
		return OpenGLWindow;
	}

	 GLboolean PressedKey(GLint key) {
		return glfwGetKey(OpenGLWindow, key);
	}

	OpenGLVertexArray::OpenGLVertexArray(GLint type) {
		glCreateVertexArrays(1, &VAO);
		EBOMode = type;
		glCreateBuffers(16, VBO);
		glCreateBuffers(16, EBO);
		glGenTextures(16, TEX);
	}

	OpenGLVertexArray::~OpenGLVertexArray(GLvoid) {
		glDeleteBuffers(16, EBO);
		glDeleteBuffers(16, VBO);
		glDeleteTextures(16, TEX);
		glDeleteVertexArrays(1, &VAO);
	}


	GLvoid OpenGLVertexArray::BufferVertexDataArray(GLint index, GLsizei bytes, GLvoid* address) {
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
		glBufferData(GL_ARRAY_BUFFER, bytes, address, GL_STATIC_DRAW);
		glBindBuffer(GL_NONE, GL_NONE);
		glBindVertexArray(GL_NONE);
	}

	GLvoid OpenGLVertexArray::BufferVertexIndexArray(GLint index, GLsizei bytes, GLvoid* address) {
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[index]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, bytes, address, GL_STATIC_DRAW);
		glBindBuffer(GL_NONE, GL_NONE);
		glBindVertexArray(GL_NONE);
	}

	GLvoid OpenGLVertexArray::UseBuffer(GLint index) {
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
		if (EBOMode == OPENGL_FALSE) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[index]);
		}
	}

	GLvoid OpenGLVertexArray::RGBTexture(GLuint index, const GLchar* path) {
		GLint TexWidth, TexHeigth, TexNRChanels;
		unsigned char* TexData = stbi_load(path, &TexWidth, &TexHeigth, &TexNRChanels, 3);
		glBindTexture(GL_TEXTURE_2D, TEX[index]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TexWidth, TexHeigth, 0, GL_RGB, GL_UNSIGNED_BYTE, TexData);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(TexData);
		
		std::cout << "Right after stuff\n";
		PrintError();
	}

	GLvoid OpenGLVertexArray::UseTexture(GLint index) {
		glActiveTexture(TextureUnit(index));
		glBindTexture(GL_TEXTURE_2D, TEX[index]);
	}

	GLuint OpenGLVertexArray::TextureUnit(GLint index) {
		switch (index) {
		case 0:
			return GL_TEXTURE0;
			break;
		case 1:
			return GL_TEXTURE1;
			break;
		case 2:
			return GL_TEXTURE2;
			break;
		case 3:
			return GL_TEXTURE3;
			break;
		case 4:
			return GL_TEXTURE4;
			break;
		case 5:
			return GL_TEXTURE5;
			break;
		case 6:
			return GL_TEXTURE6;
			break;
		case 7:
			return GL_TEXTURE7;
			break;
		case 8:
			return GL_TEXTURE8;
			break;
		case 9:
			return GL_TEXTURE9;
			break;
		case 10:
			return GL_TEXTURE10;
			break;
		case 11:
			return GL_TEXTURE11;
			break;
		case 12:
			return GL_TEXTURE12;
			break;
		case 13:
			return GL_TEXTURE13;
			break;
		case 14:
			return GL_TEXTURE14;
			break;
		case 15:
			return GL_TEXTURE15;
			break;
		default:
			break;
		}
		return 0;
	}

	OpenGLShaderProgram::OpenGLShaderProgram(GLint lang) {
		ShaderLanguage = lang;
	}

	OpenGLShaderProgram::~OpenGLShaderProgram(GLvoid) {
		glDeleteProgram(ShaderProgram);
	}

	GLvoid OpenGLShaderProgram::CompileSourceCode(const GLchar* vs, const GLchar* fs) {
		ShaderProgram = glCreateProgram();
		GLuint VertexShader = 0;
		GLuint FragmentShader = 0;
		if (ShaderLanguage = GLSL) {
			VertexShader = CompileGLSL(vs, GL_VERTEX_SHADER);
			FragmentShader = CompileGLSL(fs, GL_FRAGMENT_SHADER);
		}
		glAttachShader(ShaderProgram, VertexShader);
		glAttachShader(ShaderProgram, FragmentShader);
		glLinkProgram(ShaderProgram);
		glValidateProgram(ShaderProgram);
		GLint LinkStatus = 0;
		glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &LinkStatus);
		if (LinkStatus == GL_FALSE) {
			OpenGLConsole("Shader linking failed!");
			GLsizei len = 0;
			glGetShaderiv(ShaderProgram, GL_INFO_LOG_LENGTH, &len);
			GLchar* log = new GLchar[len]{ '\0' };
			glGetProgramInfoLog(ShaderProgram, len, &len, log);
			OpenGLConsole(log);
		}
		glDetachShader(ShaderProgram, VertexShader);
		glDetachShader(ShaderProgram, FragmentShader);
		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);
	}

	GLvoid OpenGLShaderProgram::CompileShaderFiles(const GLchar* vs, const GLchar* fs) {
		const GLchar* VertexShader = LoadShaderFile(vs);
		const GLchar* FragmentShader = LoadShaderFile(fs);
		CompileSourceCode(VertexShader, FragmentShader);
		delete[] VertexShader;
		delete[] FragmentShader;
	}

	const GLchar* OpenGLShaderProgram::LoadShaderFile(const GLchar* path) {
		GLFile* stream = fopen(path, "r");
		fseek(stream, 0, SEEK_END);
		GLuint64 length = ftell(stream);
		rewind(stream);
		GLchar* buffer = new GLchar[((int64_t)length) + 1L]{ '\0' };
		for (GLint index = 0; index < length; index++) {
			GLchar value = fgetc(stream);
			if (value == -1) {
				break;
			}
			else {
				buffer[index] = value;
			}
		}
		return buffer;
	}

	GLuint OpenGLShaderProgram::CompileGLSL(const GLchar* src, GLuint shader) {
		GLuint ShaderID = glCreateShader(shader);
		glShaderSource(ShaderID, 1, &src, nullptr);
		glCompileShader(ShaderID);
		GLint  status = 0;
		glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			GLint  msgLen;
			glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &msgLen);
			GLchar* log = new char[msgLen];
			glGetShaderInfoLog(ShaderID, msgLen, &msgLen, log);
			const GLchar* string = (const char*)log;
			std::printf("%s%c", string, '\n');
			glDeleteShader(ShaderID);
			return -1;
		}
		return ShaderID;
	}

	GLvoid OpenGLShaderProgram::UniformLocation(GLint index, const GLchar* name) {
		UniformArray[index] = glGetUniformLocation(ShaderProgram, name);
	}

	GLvoid OpenGLShaderProgram::UniformVector3D(GLint index, Vector3D vector) {
		glUniform3fv(UniformArray[index], 1, glm::value_ptr(vector));
	}

	GLvoid OpenGLShaderProgram::UniformFloat(GLint index, GLfloat value) {
		glUniform1f(UniformArray[index], value);
	}

	GLvoid OpenGLShaderProgram::UniformInteger(GLint index, GLint value) {
		glUniform1i(UniformArray[index], value);
	}

	GLvoid OpenGLShaderProgram::UniformMatrix4x4(GLint index, Matrix4x4 matrix) {
		glUniformMatrix4fv(UniformArray[index], 1, GL_FALSE, glm::value_ptr(matrix));
	}

	GLvoid OpenGLShaderProgram::UniformTransform(GLint index, OpenGLTransform transform) {
		UniformMatrix4x4(index, transform.MatrixTransform());
	}

	GLvoid OpenGLShaderProgram::UniformDirectionalLight(const GLchar* name, DirectionalLight light) {
		GLint ambient = glGetUniformLocation(ShaderProgram, CombineStrings(name, ".Ambient"));
		GLint intensity = glGetUniformLocation(ShaderProgram, CombineStrings(name, ".Intensity"));
		GLint direction = glGetUniformLocation(ShaderProgram, CombineStrings(name, ".LightDir"));
		GLint color = glGetUniformLocation(ShaderProgram, CombineStrings(name, ".LightColor"));
		glUniform1f(ambient, light.Ambient);
		glUniform1f(intensity, light.Intensity);
		glUniform3fv(direction, 1, glm::value_ptr(light.LightDir));
		glUniform3fv(color, 1, glm::value_ptr(light.LightColor));
	}

	GLvoid OpenGLShaderProgram::RunProgram(GLvoid) {
		glUseProgram(ShaderProgram);

		Matrix4x4 View = Matrix4x4(1.0f);
		CameraDir.x = cos(glm::radians(ViewCameraTransform.GetRotation().x * 360.0f)) * cos(glm::radians(ViewCameraTransform.GetRotation().y * 360.0f));
		CameraDir.y = sin(glm::radians(ViewCameraTransform.GetRotation().y * 360.0f));
		CameraDir.z = sin(glm::radians(ViewCameraTransform.GetRotation().x * 360.0f)) * cos(glm::radians(ViewCameraTransform.GetRotation().y * 360.0f));
		View = glm::lookAt(ViewCameraTransform.GetTranslation(), ViewCameraTransform.GetTranslation() + CameraDir, Vector3D(0.0f, 1.0f, 0.0f));  

		Matrix4x4 Projection = Matrix4x4(1.0f);
		if (ProjectionMode == ORTHROGRAPHIC_PROJECTION) {
			Projection = glm::ortho(0.0f, (GLfloat)FramebufferWidth, 0.0f, (GLfloat)FramebufferHeight, NearPlane, FarPlane);
		}
		else if (ProjectionMode == ISOMETRIC_PROJECTION) {
			Projection = glm::perspective(FOV, (GLfloat)FramebufferWidth / (GLfloat)FramebufferHeight, NearPlane, FarPlane);
		}

		UniformMatrix4x4(ViewMatrixIndex, View);
		UniformMatrix4x4(ProjectionMatrixIndex, Projection);
	}

	GLvoid  OpenGLShaderProgram::RenderArrays(GLuint length) {
		GLsizei Offset = 0;
		GLsizei Stride = 0;
		for (int index = 0; index < 15; index++) {
			Stride += AttributeFormat[index];
		}
		for (GLint index = 0; index < 15; index++) {
			GLsizei size = AttributeFormat[index];
			if (size == 0) {
				break;
			}
			else {
				glEnableVertexAttribArray(index);
				glVertexAttribPointer(index, size / 4, GL_FLOAT, GL_FALSE, Stride, (GLvoid*)Offset);
				Offset += size;
			}
		}
		glDrawElements(GL_TRIANGLES, length, GL_UNSIGNED_INT, 0);
		for (GLint index = 0; index < 15; index++) {
			if (AttributeFormat[index] == 0) {
				break;
			}
			else {
				glDisableVertexAttribArray(index);
			}
		}
		glUseProgram(0);
	}

	GLvoid OpenGLShaderProgram::AttributeSize(GLuint index, GLsizei bytes) {
		AttributeFormat[index] = bytes;
	}

	GLvoid OpenGLShaderProgram::TextureLocation(GLint index, const GLchar* name) {
		TextureUnit[index] = glGetUniformLocation(ShaderProgram, name);
	}

	GLvoid OpenGLShaderProgram::TextureUniform(GLint index) {
		glUniform1i(TextureUnit[index], index);
	}


	GLvoid OpenGLShaderProgram::ProjectionIndex(GLuint index) {
		ProjectionMatrixIndex = index;
	}

	GLvoid OpenGLShaderProgram::ViewIndex(GLuint index) {
		ViewMatrixIndex = index;
	}

	OpenGLTransform::OpenGLTransform(Matrix4x4 transform) {
		Transform = transform;
	}

	OpenGLTransform::~OpenGLTransform(GLvoid) {

	}

	GLvoid OpenGLTransform::Rotate(Vector3D arg) {
		RotationVector += arg;
	}

	GLvoid OpenGLTransform::SetRotate(Vector3D arg) {
		RotationVector = arg;
	}

	GLvoid OpenGLTransform::Scale(Vector3D arg) {
		ScaleVector += arg;
	}

	GLvoid OpenGLTransform::SetScale(Vector3D arg) {
		ScaleVector = arg;
	}

	GLvoid OpenGLTransform::Translate(Vector3D arg) {
		TranslationVector += arg;
	}

	GLvoid OpenGLTransform::SetTranslate(Vector3D arg) {
		TranslationVector = arg;
	}

	Vector3D OpenGLTransform::GetTranslation(GLvoid) {
		return TranslationVector;
	}

	Vector3D OpenGLTransform::GetScale(GLvoid) {
		return ScaleVector;
	}

	Vector3D OpenGLTransform::GetRotation(GLvoid) {
		return RotationVector;
	}

	Matrix4x4 OpenGLTransform::MatrixTransform(GLvoid) {
		const Vector3D X_AXIS = Vector3D(1.0f, 0.0f, 0.0f);
		const Vector3D Y_AXIS = Vector3D(0.0f, 1.0f, 0.0f);
		const Vector3D Z_AXIS = Vector3D(0.0f, 0.0f, 1.0f);
		Transform = Matrix4x4(1.0f);
		Transform = glm::rotate(Transform, RotationVector.x * glm::radians(360.0f), X_AXIS);
		Transform = glm::rotate(Transform, RotationVector.y * glm::radians(360.0f), Y_AXIS);
		Transform = glm::rotate(Transform, RotationVector.z * glm::radians(360.0f), Z_AXIS);
		Transform = glm::scale(Transform, ScaleVector);
		//Transform = glm::translate(Transform, TranslationVector);
		Transform[3][0] = TranslationVector.x;
		Transform[3][1] = TranslationVector.y;
		Transform[3][2] = TranslationVector.z;
		return Transform;
	}

}