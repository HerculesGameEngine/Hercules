#include "ImageLoader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../ThirdParty/stb/stb_image.h"

namespace Hercules {

bool ImageLoader::load(
    const std::string& path,
    Image& image
) {
    int width = 0;
    int height = 0;
    int channels = 0;

    unsigned char* data =
        stbi_load(
            path.c_str(),
            &width,
            &height,
            &channels,
            4
        );

    if (!data) {
        return false;
    }

    if (!image.create(width, height, 4)) {
        stbi_image_free(data);
        return false;
    }

    const size_t size =
        static_cast<size_t>(width) *
        static_cast<size_t>(height) *
        4;

    for (size_t i = 0; i < size; ++i) {
        image.getPixels()[i] = data[i];
    }

    stbi_image_free(data);

    return true;
}

bool ImageLoader::loadPNG(
    const std::string& path,
    Image& image
) {
    return load(path, image);
}

bool ImageLoader::loadJPG(
    const std::string& path,
    Image& image
) {
    return load(path, image);
}

bool ImageLoader::loadTGA(
    const std::string& path,
    Image& image
) {
    return load(path, image);
}

}
