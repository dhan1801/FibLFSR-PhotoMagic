// Copyright 2025 Dhanvika Nakka
#ifndef PHOTOMAGIC_HPP
#define PHOTOMAGIC_HPP

#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {
void transform(sf::Image& img, FibLFSR* lfsr);
}

#endif
