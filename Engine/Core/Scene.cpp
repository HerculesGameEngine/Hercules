#include "Scene.hpp"
#include "GameObject.hpp"

namespace Hercules {

Scene::Scene() {
}

Scene::~Scene() {
    clear();
}

void Scene::start() {
    // Inicialização da cena
}

void Scene::update(float deltaTime) {
    for (auto& object : objects) {
        object->update(deltaTime);
    }
}

GameObject* Scene::createGameObject(const char* name) {
    auto object = std::make_unique<GameObject>(name);

    GameObject* pointer = object.get();

    objects.push_back(std::move(object));

    return pointer;
}

void Scene::clear() {
    objects.clear();
}

}
