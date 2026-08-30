#include "OpenGLShader.hpp"

#ifdef _WIN32

#include <windows.h>
#include <GL/gl.h>

namespace Hercules {

OpenGLShader::OpenGLShader()
    : program(0) {
}

OpenGLShader::~OpenGLShader() {
    destroy();
}

unsigned int OpenGLShader::compileShader(
    unsigned int type,
    const char* source
) {
    GLuint shader =
        glCreateShader(type);

    glShaderSource(
        shader,
        1,
        &source,
        nullptr
    );

    glCompileShader(shader);

    GLint success = GL_FALSE;

    glGetShaderiv(
        shader,
        GL_COMPILE_STATUS,
        &success
    );

    if (!success) {
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

bool OpenGLShader::create(
    const char* vertexSource,
    const char* fragmentSource
) {
    destroy();

    GLuint vertex =
        compileShader(
            GL_VERTEX_SHADER,
            vertexSource
        );

    if (!vertex)
        return false;

    GLuint fragment =
        compileShader(
            GL_FRAGMENT_SHADER,
            fragmentSource
        );

    if (!fragment) {
        glDeleteShader(vertex);
        return false;
    }

    program =
        glCreateProgram();

    glAttachShader(
        program,
        vertex
    );

    glAttachShader(
        program,
        fragment
    );

    glLinkProgram(program);

    GLint success = GL_FALSE;

    glGetProgramiv(
        program,
        GL_LINK_STATUS,
        &success
    );

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    if (!success) {
        destroy();
        return false;
    }

    return true;
}

void OpenGLShader::bind() const {
    glUseProgram(program);
}

void OpenGLShader::destroy() {

    if (program) {
        glDeleteProgram(program);
        program = 0;
    }
}

unsigned int OpenGLShader::getProgram() const {
    return program;
}

}

#endif
