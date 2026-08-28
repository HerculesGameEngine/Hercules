#include "GameObject.hpp"

namespace Hercules {

GameObject::GameObject(const std::string& name)
    : name(name) {
}

GameObject::~GameObject() {
}

void GameObject::update(float deltaTime) {
    (void)deltaTime;

    // Atualização dos componentes futuramente
}

const std::string& GameObject::getName() const {
    return name;
}

Transform& GameObject::getTransform() {
    return transform;
}

}
