#include "Mesh.hpp"
#include "OBJLoader.hpp"

namespace Hercules {

Mesh::Mesh()
    : loaded(false) {
}

bool Mesh::loadOBJ(
    const std::string& path
) {
    clear();

    loaded =
        OBJLoader::load(
            path,
            *this
        );

    return loaded;
}

void Mesh::clear()
{
    vertices.clear();
    indices.clear();

    loaded = false;
}

const std::vector<Vertex>&
Mesh::getVertices() const
{
    return vertices;
}

const std::vector<unsigned int>&
Mesh::getIndices() const
{
    return indices;
}

bool Mesh::isLoaded() const
{
    return loaded;
}

}
