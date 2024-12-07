#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>  // OpenGL 扩展库
#include <GL/glut.h>   // 包含GLUT，GLUT会自动包含gl.h

class Shader {
public:
    GLuint program;  // 着色器程序 ID

    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use();  // 使用着色器程序
    GLuint getUniformLocation(const std::string& name);

private:
    GLuint loadShader(const std::string& path, GLenum shaderType);
    GLuint vertexShader, fragmentShader;

    std::string readShaderFile(const std::string& path);
};

#endif
