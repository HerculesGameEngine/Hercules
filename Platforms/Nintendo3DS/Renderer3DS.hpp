#pragma once

#include "../../Engine/Graphics/Renderer.hpp"

#include <3ds.h>
#include <citro3d.h>

namespace Hercules {

class Renderer3DS final : public Renderer {
public:
    Renderer3DS();
    ~Renderer3DS() override;

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
    C3D_RenderTarget* topLeft;

    Camera camera;

    bool initialized;
};

}
