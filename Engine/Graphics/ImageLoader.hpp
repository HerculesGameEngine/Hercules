#pragma once

#include <string>

#include "Image.hpp"

namespace Hercules {

class ImageLoader {
public:
    static bool load(
        const std::string& path,
        Image& image
    );

    static bool loadPNG(
        const std::string& path,
        Image& image
    );

    static bool loadJPG(
        const std::string& path,
        Image& image
    );

    static bool loadTGA(
        const std::string& path,
        Image& image
    );
};

}
