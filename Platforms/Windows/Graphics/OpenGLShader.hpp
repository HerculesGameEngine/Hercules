#pragma once

#include <string>

namespace Hercules {

class OpenGLShader {
public:
    OpenGLShader();
    ~OpenGLShader();

    bool create(
        const char* vertexSource,
        const char* fragmentSource
    );

    void bind() const;
    void destroy();

    unsigned int getProgram() const;

private:
    unsigned int program;

    unsigned int compileShader(
        unsigned int type,
        const char* source
    );
};

}
