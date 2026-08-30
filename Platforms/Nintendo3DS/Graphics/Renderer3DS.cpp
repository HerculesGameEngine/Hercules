#include "Renderer3DS.hpp"

namespace Hercules {

Renderer3DS::Renderer3DS()
    : topLeft(nullptr),
      initialized(false) {
}

Renderer3DS::~Renderer3DS() {
    shutdown();
}

bool Renderer3DS::initialize(
    int width,
    int height,
    const char* title
) {
    (void)width;
    (void)height;
    (void)title;

    /*
     * libctru:
     * Inicializa o hardware/sistema do 3DS.
     */
    gfxInitDefault();

    /*
     * Citro3D:
     * Inicializa o sistema de renderização 3D.
     */
    if (!C3D_Init(C3D_DEFAULT_CMDBUF_SIZE)) {
        gfxExit();
        return false;
    }

    /*
     * Tela superior esquerda:
     *
     * 400 x 240
     */
    topLeft = C3D_RenderTargetCreate(
        400,
        240,
        GPU_RB_RGBA8,
        GPU_RB_DEPTH24_STENCIL8
    );

    if (!topLeft) {
        C3D_Fini();
        gfxExit();

        return false;
    }

    /*
     * Citro3D envia o framebuffer
     * para a tela superior esquerda.
     */
    C3D_RenderTargetSetOutput(
        topLeft,
        GFX_TOP,
        GFX_LEFT,
        DISPLAY_TRANSFER_FLAGS
    );

    initialized = true;

    return true;
}

void Renderer3DS::beginFrame() {

    if (!initialized)
        return;

    C3D_FrameBegin(
        C3D_FRAME_SYNCDRAW
    );
}

void Renderer3DS::clear(
    const Color& color
) {
    if (!initialized)
        return;

    /*
     * Converte RGBA float
     * para RGBA8.
     */
    uint8_t r =
        static_cast<uint8_t>(
            color.r * 255.0f
        );

    uint8_t g =
        static_cast<uint8_t>(
            color.g * 255.0f
        );

    uint8_t b =
        static_cast<uint8_t>(
            color.b * 255.0f
        );

    uint8_t a =
        static_cast<uint8_t>(
            color.a * 255.0f
        );

    uint32_t rgba =
        (r << 24) |
        (g << 16) |
        (b << 8) |
        a;

    C3D_RenderTargetClear(
        topLeft,
        C3D_CLEAR_ALL,
        rgba,
        0
    );
}

void Renderer3DS::setCamera(
    const Camera& newCamera
) {
    camera = newCamera;
}

void Renderer3DS::drawMesh(
    const Mesh& mesh,
    const Material& material
) {
    /*
     * Aqui será conectado:
     *
     * Hercules Mesh
     *      ↓
     * Citro3D vertex buffer
     *      ↓
     * Citro3D shader
     *      ↓
     * GPU do 3DS
     */

    (void)mesh;
    (void)material;
}

void Renderer3DS::endFrame() {

    if (!initialized)
        return;

    C3D_FrameEnd(0);
}

void Renderer3DS::shutdown() {

    if (!initialized)
        return;

    if (topLeft) {
        C3D_RenderTargetDelete(
            topLeft
        );

        topLeft = nullptr;
    }

    /*
     * Finaliza Citro3D.
     */
    C3D_Fini();

    /*
     * Finaliza libctru/gfx.
     */
    gfxExit();

    initialized = false;
}

const char* Renderer3DS::getName() const {
    return "Hercules Renderer - Nintendo 3DS";
}

}
