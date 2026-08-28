#include "MaterialMaker.hpp"

namespace Hercules {

std::unique_ptr<Material>
MaterialMaker::create() {

    return std::make_unique<Material>();
}

std::unique_ptr<Material>
MaterialMaker::createColor(
    const Color& color
) {

    auto material =
        std::make_unique<Material>();

    material->setColor(color);

    return material;
}

std::unique_ptr<Material>
MaterialMaker::createTexture(
    Texture* texture
) {

    auto material =
        std::make_unique<Material>();

    material->setTexture(texture);

    return material;
}

std::unique_ptr<Material>
MaterialMaker::load(
    const std::string& path
) {
    // Loader .hmat será implementado aqui.
    (void)path;

    return nullptr;
}

}
