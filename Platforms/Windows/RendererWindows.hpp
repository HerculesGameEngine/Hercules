#pragma once

#include "../../Engine/Graphics/Renderer.hpp"

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace Hercules {

class RendererWindows final : public Renderer {
public:
    RendererWindows();
    ~RendererWindows() override;

    bool initialize(
        int width,
        int height,
        const char* title
    ) override;

    void beginFrame() override;

    void clear(
        const Color& color
    ) override;

    void setCamera(
        const Camera& camera
    ) override;

    void drawMesh(
        const Mesh& mesh,
        const Material& material
    ) override;

    void endFrame() override;

    void shutdown() override;

    const char* getName() const override;

private:
    HWND window;
    HDC deviceContext;
    HGLRC glContext;

    Camera currentCamera;

    bool initialized;

    int width;
    int height;
};

}

#endif
