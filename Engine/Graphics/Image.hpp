#pragma once

#include <cstdint>

namespace Hercules {

class Image {
public:
    Image();
    ~Image();

    bool create(
        int width,
        int height,
        int channels = 4
    );

    void destroy();

    uint8_t* getPixels();
    const uint8_t* getPixels() const;

    int getWidth() const;
    int getHeight() const;
    int getChannels() const;

    bool isValid() const;

private:
    int width;
    int height;
    int channels;

    uint8_t* pixels;
};

}
