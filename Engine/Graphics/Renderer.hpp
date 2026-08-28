#pragma once

#include "Mesh.hpp"
#include "Material.hpp"
#include "Camera.hpp"

namespace Hercules {

class Renderer {
public:
    virtual ~Renderer() = default;

    // Inicialização
    virtual bool initialize(
        int width,
        int height,
        const char* title
    ) = 0;

    // Frame
    virtual void beginFrame() = 0;

    virtual void clear(
        const Color& color
    ) = 0;

    // Câmera
    virtual void setCamera(
        const Camera& camera
    ) = 0;

    // Renderização 3D
    virtual void drawMesh(
        const Mesh& mesh,
        const Material& material
    ) = 0;

    // Apresentar frame
    virtual void endFrame() = 0;

    // Finalização
    virtual void shutdown() = 0;

    // Informações
    virtual const char* getName() const = 0;
};

}
