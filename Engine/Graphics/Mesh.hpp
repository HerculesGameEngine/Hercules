#pragma once

#include <string>
#include <vector>
#include "Vertex.hpp"

namespace Hercules {

class Mesh {
public:
    Mesh();
    ~Mesh();

    bool loadOBJ(const std::string& path);

    void setVertices(const std::vector<Vertex>& vertices);
    void setIndices(const std::vector<unsigned int>& indices);

    const std::vector<Vertex>& getVertices() const;
    const std::vector<unsigned int>& getIndices() const;

private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

}
