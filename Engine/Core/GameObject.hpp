#pragma once

#include <string>
#include "Transform.hpp"

namespace Hercules {

class GameObject {
public:
    explicit GameObject(const std::string& name = "GameObject");
    ~GameObject();

    void update(float deltaTime);

    const std::string& getName() const;

    Transform& getTransform();

private:
    std::string name;
    Transform transform;
};

}
