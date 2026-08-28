#pragma once

#include <memory>
#include <string>

#include "Material.hpp"

namespace Hercules {

class Texture;

class MaterialMaker {
public:

    static std::unique_ptr<Material> create();

    static std::unique_ptr<Material> createColor(
        const Color& color
    );

    static std::unique_ptr<Material> createTexture(
        Texture* texture
    );

    static std::unique_ptr<Material> load(
        const std::string& path
    );
};

}
