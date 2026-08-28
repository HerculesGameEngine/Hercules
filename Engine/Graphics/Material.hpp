#pragma once

#include "Color.hpp"

namespace Hercules {

class Texture;

class Material {
public:
    Material();

    void setColor(const Color& color);
    void setTexture(Texture* texture);

    void setMetallic(float value);
    void setRoughness(float value);

    const Color& getColor() const;
    Texture* getTexture() const;

    float getMetallic() const;
    float getRoughness() const;

private:
    Color color;

    Texture* texture;

    float metallic;
    float roughness;
};

}
