#include "Material.hpp"

namespace Hercules {

Material::Material()
    : color(1.0f, 1.0f, 1.0f, 1.0f),
      texture(nullptr),
      metallic(0.0f),
      roughness(0.5f) {
}

void Material::setColor(const Color& color) {
    this->color = color;
}

void Material::setTexture(Texture* texture) {
    this->texture = texture;
}

void Material::setMetallic(float value) {
    metallic = value;
}

void Material::setRoughness(float value) {
    roughness = value;
}

const Color& Material::getColor() const {
    return color;
}

Texture* Material::getTexture() const {
    return texture;
}

float Material::getMetallic() const {
    return metallic;
}

float Material::getRoughness() const {
    return roughness;
}

}
