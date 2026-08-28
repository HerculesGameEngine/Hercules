#include "Camera.hpp"

namespace Hercules {

Camera::Camera()
    : position(0.0f, 0.0f, 0.0f),
      rotation(0.0f, 0.0f, 0.0f),
      fov(60.0f),
      nearClip(0.1f),
      farClip(1000.0f) {
}

void Camera::setPosition(const Vector3& position) {
    this->position = position;
}

void Camera::setRotation(const Vector3& rotation) {
    this->rotation = rotation;
}

const Vector3& Camera::getPosition() const {
    return position;
}

const Vector3& Camera::getRotation() const {
    return rotation;
}

void Camera::setFOV(float fov) {
    this->fov = fov;
}

float Camera::getFOV() const {
    return fov;
}

void Camera::setNearClip(float value) {
    nearClip = value;
}

void Camera::setFarClip(float value) {
    farClip = value;
}

float Camera::getNearClip() const {
    return nearClip;
}

float Camera::getFarClip() const {
    return farClip;
}

}
