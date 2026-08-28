#pragma once

#include "../Core/Transform.hpp"

namespace Hercules {

class Camera {
public:
    Camera();

    void setPosition(const Vector3& position);
    void setRotation(const Vector3& rotation);

    const Vector3& getPosition() const;
    const Vector3& getRotation() const;

    void setFOV(float fov);
    float getFOV() const;

    void setNearClip(float value);
    void setFarClip(float value);

    float getNearClip() const;
    float getFarClip() const;

private:
    Vector3 position;
    Vector3 rotation;

    float fov;
    float nearClip;
    float farClip;
};

}
