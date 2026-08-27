#include "Transform.hpp"

namespace Hercules {

Vector3::Vector3()
    : x(0.0f), y(0.0f), z(0.0f) {
}

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z) {
}

Transform::Transform()
    : position(0.0f, 0.0f, 0.0f),
      rotation(0.0f, 0.0f, 0.0f),
      scale(1.0f, 1.0f, 1.0f) {
}

}
