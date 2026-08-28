#include "Image.hpp"

#include <new>

namespace Hercules {

Image::Image()
    : width(0),
      height(0),
      channels(0),
      pixels(nullptr) {
}

Image::~Image() {
    destroy();
}

bool Image::create(
    int width,
    int height,
    int channels
) {
    destroy();

    if (width <= 0 ||
        height <= 0 ||
        channels <= 0) {
        return false;
    }

    this->width = width;
    this->height = height;
    this->channels = channels;

    const size_t size =
        static_cast<size_t>(width) *
        static_cast<size_t>(height) *
        static_cast<size_t>(channels);

    pixels = new (std::nothrow) uint8_t[size];

    if (!pixels) {
        width = 0;
        height = 0;
        channels = 0;

        return false;
    }

    return true;
}

void Image::destroy() {

    delete[] pixels;

    pixels = nullptr;

    width = 0;
    height = 0;
    channels = 0;
}

uint8_t* Image::getPixels() {
    return pixels;
}

const uint8_t* Image::getPixels() const {
    return pixels;
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

int Image::getChannels() const {
    return channels;
}

bool Image::isValid() const {
    return pixels != nullptr &&
           width > 0 &&
           height > 0;
}

}
