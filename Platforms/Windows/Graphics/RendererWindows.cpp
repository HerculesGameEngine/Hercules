#include "RendererWindows.hpp"

#ifdef _WIN32

#include <gl/GL.h>

namespace Hercules {

static const char* WINDOW_CLASS_NAME =
    "HerculesEngineWindow";

static LRESULT CALLBACK WindowProcedure(
    HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (message) {

        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProcA(
                hwnd,
                message,
                wParam,
                lParam
            );
    }
}

RendererWindows::RendererWindows()
    : window(nullptr),
      deviceContext(nullptr),
      glContext(nullptr),
      currentCamera(),
      initialized(false),
      width(0),
      height(0)
{
}

RendererWindows::~RendererWindows()
{
    shutdown();
}

bool RendererWindows::initialize(
    int width,
    int height,
    const char* title
)
{
    this->width = width;
    this->height = height;

    HINSTANCE instance =
        GetModuleHandleA(nullptr);

    WNDCLASSA windowClass{};

    windowClass.style =
        CS_OWNDC;

    windowClass.lpfnWndProc =
        WindowProcedure;

    windowClass.hInstance =
        instance;

    windowClass.lpszClassName =
        WINDOW_CLASS_NAME;

    if (!RegisterClassA(&windowClass)) {

        if (GetLastError() !=
            ERROR_CLASS_ALREADY_EXISTS) {

            return false;
        }
    }

    window =
        CreateWindowExA(
            0,
            WINDOW_CLASS_NAME,
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            width,
            height,
            nullptr,
            nullptr,
            instance,
            nullptr
        );

    if (!window) {
        return false;
    }

    deviceContext =
        GetDC(window);

    if (!deviceContext) {
        DestroyWindow(window);
        window = nullptr;

        return false;
    }

    PIXELFORMATDESCRIPTOR pfd{};

    pfd.nSize =
        sizeof(PIXELFORMATDESCRIPTOR);

    pfd.nVersion = 1;

    pfd.dwFlags =
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_DOUBLEBUFFER;

    pfd.iPixelType =
        PFD_TYPE_RGBA;

    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;

    int pixelFormat =
        ChoosePixelFormat(
            deviceContext,
            &pfd
        );

    if (pixelFormat == 0) {
        shutdown();
        return false;
    }

    if (!SetPixelFormat(
            deviceContext,
            pixelFormat,
            &pfd)) {

        shutdown();
        return false;
    }

    glContext =
        wglCreateContext(
            deviceContext
        );

    if (!glContext) {
        shutdown();
        return false;
    }

    if (!wglMakeCurrent(
            deviceContext,
            glContext)) {

        shutdown();
        return false;
    }

    ShowWindow(
        window,
        SW_SHOW
    );

    UpdateWindow(window);

    glViewport(
        0,
        0,
        width,
        height
    );

    glEnable(GL_DEPTH_TEST);

    glClearColor(
        0.05f,
        0.05f,
        0.12f,
        1.0f
    );

    initialized = true;

    return true;
}

void RendererWindows::beginFrame()
{
    if (!initialized)
        return;
}

void RendererWindows::clear(
    const Color& color
)
{
    if (!initialized)
        return;

    glClearColor(
        color.r,
        color.g,
        color.b,
        color.a
    );

    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );
}

void RendererWindows::setCamera(
    const Camera& camera
)
{
    currentCamera = camera;
}

void RendererWindows::drawMesh(
    const Mesh& mesh,
    const Material& material
)
{
    /*
     * Futuramente:
     *
     * Hercules Mesh
     *       ↓
     * OpenGL Vertex Buffer
     *       ↓
     * Shader
     *       ↓
     * Material
     *       ↓
     * OpenGL
     */

    (void)mesh;
    (void)material;
}

void RendererWindows::endFrame()
{
    if (!initialized)
        return;

    SwapBuffers(
        deviceContext
    );
}

void RendererWindows::shutdown()
{
    if (glContext) {

        wglMakeCurrent(
            nullptr,
            nullptr
        );

        wglDeleteContext(
            glContext
        );

        glContext = nullptr;
    }

    if (deviceContext && window) {

        ReleaseDC(
            window,
            deviceContext
        );

        deviceContext = nullptr;
    }

    if (window) {

        DestroyWindow(
            window
        );

        window = nullptr;
    }

    initialized = false;
}

const char* RendererWindows::getName() const
{
    return "Hercules Renderer - Windows";
}

}

#endif
