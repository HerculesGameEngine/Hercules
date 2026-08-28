#pragma once

#include "../Core/Transform.hpp"

namespace Hercules {

struct Vertex {
    Vector3 position;
    Vector3 normal;

    float u;
    float v;

    Vertex()
        : position(),
          normal(),
          u(0.0f),
          v(0.0f) {
    }

    Vertex(
        Vector3 position,
        Vector3 normal,
        float u,
        float v
    )
        : position(position),
          normal(normal),
          u(u),
          v(v) {
    }
};

}
