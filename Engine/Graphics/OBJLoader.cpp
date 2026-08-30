#include "OBJLoader.hpp"

#include <fstream>
#include <sstream>

#include <vector>

namespace Hercules {

bool OBJLoader::load(
    const std::string& path,
    Mesh& mesh
) {
    std::ifstream file(path);

    if (!file.is_open()) {
        return false;
    }

    std::vector<Vector3> positions;
    std::vector<Vector3> normals;
    std::vector<Vector2> texcoords;

    std::string line;

    while (std::getline(file, line)) {

        std::stringstream stream(line);

        std::string type;
        stream >> type;

        // -----------------------------
        // Vertex position
        // -----------------------------

        if (type == "v") {

            float x, y, z;

            stream >> x >> y >> z;

            positions.emplace_back(
                x, y, z
            );
        }

        // -----------------------------
        // Texture coordinate
        // -----------------------------

        else if (type == "vt") {

            float u, v;

            stream >> u >> v;

            texcoords.emplace_back(
                u, v
            );
        }

        // -----------------------------
        // Normal
        // -----------------------------

        else if (type == "vn") {

            float x, y, z;

            stream >> x >> y >> z;

            normals.emplace_back(
                x, y, z
            );
        }

        // -----------------------------
        // Face
        // -----------------------------

        else if (type == "f") {

            std::string face;

            std::vector<unsigned int>
                faceIndices;

            while (stream >> face) {

                int positionIndex = 0;
                int texcoordIndex = 0;
                int normalIndex = 0;

                /*
                 * Formatos aceitos:
                 *
                 * v
                 * v/vt
                 * v/vt/vn
                 * v//vn
                 */

                sscanf(
                    face.c_str(),
                    "%d/%d/%d",
                    &positionIndex,
                    &texcoordIndex,
                    &normalIndex
                );

                Vertex vertex{};

                if (positionIndex > 0 &&
                    positionIndex <=
                    static_cast<int>(
                        positions.size()
                    )) {

                    vertex.position =
                        positions[
                            positionIndex - 1
                        ];
                }

                if (texcoordIndex > 0 &&
                    texcoordIndex <=
                    static_cast<int>(
                        texcoords.size()
                    )) {

                    vertex.uv =
                        texcoords[
                            texcoordIndex - 1
                        ];
                }

                if (normalIndex > 0 &&
                    normalIndex <=
                    static_cast<int>(
                        normals.size()
                    )) {

                    vertex.normal =
                        normals[
                            normalIndex - 1
                        ];
                }

                faceIndices.push_back(
                    static_cast<unsigned int>(
                        mesh.vertices.size()
                    )
                );

                mesh.vertices.push_back(
                    vertex
                );
            }

            /*
             * OBJ normalmente usa triângulos,
             * mas também pode ter quads/polígonos.
             *
             * Fazemos triangulação em fan.
             */

            if (faceIndices.size() >= 3) {

                for (
                    size_t i = 1;
                    i + 1 < faceIndices.size();
                    ++i
                ) {

                    mesh.indices.push_back(
                        faceIndices[0]
                    );

                    mesh.indices.push_back(
                        faceIndices[i]
                    );

                    mesh.indices.push_back(
                        faceIndices[i + 1]
                    );
                }
            }
        }
    }

    file.close();

    return !mesh.vertices.empty();
}

}
