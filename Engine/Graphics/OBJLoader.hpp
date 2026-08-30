#pragma once

#include "Mesh.hpp"

#include <string>

namespace Hercules {

class OBJLoader {
public:
    static bool load(
        const std::string& path,
        Mesh& mesh
    );
};

}
