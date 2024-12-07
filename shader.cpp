#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    vertexShader = loadShader(vertexPath, GL_VERTEX_SHADER);
    fragmentShader = loadShader(fragmentPath, GL_FRAGMENT_SHADER);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(program);
}

void Shader::use() {
    glUseProgram(program);
}

GLuint Shader::getUniformLocation(const std::string& name) {
    return glGetUniformLocation(program, name.c_str());
}

GLuint Shader::loadShader(const std::string& path, GLenum shaderType) {
    std::string shaderSource = readShaderFile(path);
    const char* shaderCode = shaderSource.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

std::string Shader::readShaderFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream shaderStream;
    shaderStream << file.rdbuf();
    return shaderStream.str();
}
