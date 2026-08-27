#pragma once

namespace Hercules {

class GameObject;

class Component {
public:
    virtual ~Component() = default;

    virtual void start() {}
    virtual void update(float deltaTime) {}

    void setOwner(GameObject* object) {
        owner = object;
    }

    GameObject* getOwner() const {
        return owner;
    }

protected:
    GameObject* owner = nullptr;
};

}
