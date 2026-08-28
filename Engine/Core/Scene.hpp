#pragma once

#include <memory>
#include <vector>

namespace Hercules {

class GameObject;

class Scene {
public:
    Scene();
    ~Scene();

    void start();
    void update(float deltaTime);

    GameObject* createGameObject(const char* name);

    void clear();

private:
    std::vector<std::unique_ptr<GameObject>> objects;
};

}
