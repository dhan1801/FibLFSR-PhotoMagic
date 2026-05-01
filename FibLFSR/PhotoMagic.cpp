// Copyright 2025 Dhanvika Nakka
#include "PhotoMagic.hpp"

namespace PhotoMagic {
void transform(sf::Image& img, FibLFSR* lfsr) {
        sf::Vector2u size = img.getSize();
        for (unsigned int y = 0; y < size.y; ++y) {
            for (unsigned int x = 0; x < size.x; ++x) {
                sf::Color pixel = img.getPixel(x, y);
                pixel.r = pixel.r ^ (lfsr->generate(8) & 0xFF);
                pixel.g = pixel.g ^ (lfsr->generate(8) & 0xFF);
                pixel.b = pixel.b ^ (lfsr->generate(8) & 0xFF);
                img.setPixel(x, y, pixel);
            }
        }
}
}  // namespace PhotoMagic
