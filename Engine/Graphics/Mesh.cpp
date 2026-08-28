#include "Mesh.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace Hercules {

Mesh::Mesh() {
}

Mesh::~Mesh() {
}

bool Mesh::loadOBJ(const std::string& path) {

    std::ifstream file(path);

    if (!file.is_open()) {
        return false;
    }

    // Limpa o mesh atual
    vertices.clear();
    indices.clear();

    std::vector<Vector3> positions;
    std::vector<Vector3> normals;

    struct UV {
        float u;
        float v;
    };

    std::vector<UV> texcoords;

    std::string line;

    while (std::getline(file, line)) {

        if (line.empty() || line[0] == '#') {
            continue;
        }

        std::stringstream stream(line);

        std::string type;
        stream >> type;

        // -------------------------
        // Vertex position
        // -------------------------
        if (type == "v") {

            float x;
            float y;
            float z;

            stream >> x >> y >> z;

            positions.emplace_back(x, y, z);
        }

        // -------------------------
        // Texture coordinate
        // -------------------------
        else if (type == "vt") {

            float u;
            float v;

            stream >> u >> v;

            texcoords.push_back({u, v});
        }

        // -------------------------
        // Normal
        // -------------------------
        else if (type == "vn") {

            float x;
            float y;
            float z;

            stream >> x >> y >> z;

            normals.emplace_back(x, y, z);
        }

        // -------------------------
        // Face
        // -------------------------
        else if (type == "f") {

            std::vector<std::string> face;

            std::string vertex;

            while (stream >> vertex) {
                face.push_back(vertex);
            }

            if (face.size() < 3) {
                continue;
            }

            // Triangulação em fan:
            //
            // 0---1
            // |\  |
            // | \ |
            // 3---2
            //
            // vira:
            // 0 1 2
            // 0 2 3

            for (size_t i = 1; i + 1 < face.size(); ++i) {

                std::string triangle[3] = {
                    face[0],
                    face[i],
                    face[i + 1]
                };

                for (int j = 0; j < 3; ++j) {

                    int positionIndex = 0;
                    int texcoordIndex = 0;
                    int normalIndex = 0;

                    std::stringstream vertexStream(triangle[j]);

                    std::string positionString;
                    std::string texcoordString;
                    std::string normalString;

                    std::getline(
                        vertexStream,
                        positionString,
                        '/'
                    );

                    std::getline(
                        vertexStream,
                        texcoordString,
                        '/'
                    );

                    std::getline(
                        vertexStream,
                        normalString,
                        '/'
                    );

                    // -------------------------
                    // Position
                    // -------------------------

                    if (!positionString.empty()) {
                        positionIndex =
                            std::stoi(positionString);
                    }

                    // -------------------------
                    // UV
                    // -------------------------

                    if (!texcoordString.empty()) {
                        texcoordIndex =
                            std::stoi(texcoordString);
                    }

                    // -------------------------
                    // Normal
                    // -------------------------

                    if (!normalString.empty()) {
                        normalIndex =
                            std::stoi(normalString);
                    }

                    // OBJ usa índices começando em 1.
                    // Também permite índices negativos.

                    if (positionIndex < 0) {
                        positionIndex =
                            static_cast<int>(
                                positions.size()
                            ) + positionIndex + 1;
                    }

                    if (texcoordIndex < 0) {
                        texcoordIndex =
                            static_cast<int>(
                                texcoords.size()
                            ) + texcoordIndex + 1;
                    }

                    if (normalIndex < 0) {
                        normalIndex =
                            static_cast<int>(
                                normals.size()
                            ) + normalIndex + 1;
                    }

                    Vector3 position(0.0f, 0.0f, 0.0f);
                    Vector3 normal(0.0f, 0.0f, 0.0f);

                    float u = 0.0f;
                    float v = 0.0f;

                    // OBJ -> índice C++
                    if (positionIndex > 0 &&
                        positionIndex <=
                            static_cast<int>(positions.size())) {

                        position =
                            positions[positionIndex - 1];
                    }

                    if (texcoordIndex > 0 &&
                        texcoordIndex <=
                            static_cast<int>(texcoords.size())) {

                        u =
                            texcoords[texcoordIndex - 1].u;

                        v =
                            texcoords[texcoordIndex - 1].v;
                    }

                    if (normalIndex > 0 &&
                        normalIndex <=
                            static_cast<int>(normals.size())) {

                        normal =
                            normals[normalIndex - 1];
                    }

                    vertices.emplace_back(
                        position,
                        normal,
                        u,
                        v
                    );

                    indices.push_back(
                        static_cast<unsigned int>(
                            vertices.size() - 1
                        )
                    );
                }
            }
        }
    }

    file.close();

    return !vertices.empty();
}

void Mesh::setVertices(
    const std::vector<Vertex>& vertices
) {
    this->vertices = vertices;
}

void Mesh::setIndices(
    const std::vector<unsigned int>& indices
) {
    this->indices = indices;
}

const std::vector<Vertex>& Mesh::getVertices() const {
    return vertices;
}

const std::vector<unsigned int>& Mesh::getIndices() const {
    return indices;
}

}
