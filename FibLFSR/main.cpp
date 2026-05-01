// Copyright 2025 Dhanvika Nakka
#include <cstdint>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

std::string passwordToSeed(const std::string& password) {
    uint64_t sum = 0;
    for (char c : password) {
        sum = (sum * 31 + static_cast<unsigned int>(c)) % (1ULL << 16);
    }

    std::string binary = "";
    for (int i = 0; i < 16; ++i) {
        binary = std::to_string((sum >> (15 - i)) & 1) + binary;
    }
    return binary;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0]
                  << " input-file.png output-file.png seed-or-password" << std::endl;
        return -1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string seedInput = argv[3];
    std::string seed;


    bool isBinarySeed = seedInput.length() == 16 &&
                        seedInput.find_first_not_of("01") == std::string::npos;

    if (!isBinarySeed) {
        seed = passwordToSeed(seedInput);
        std::cout << "Converted password to seed: " << seed << std::endl;
    } else {
        seed = seedInput;
    }

    sf::Image image;
    if (!image.loadFromFile(inputFile)) {
        std::cerr << "Failed to load image: " << inputFile << std::endl;
        return -1;
    }

    sf::Image originalImage = image;
    PhotoMagic::FibLFSR lfsr(seed);
    PhotoMagic::transform(image, &lfsr);

    sf::Vector2u size = image.getSize();

    sf::RenderWindow windowOriginal(sf::VideoMode(size.x, size.y), "Original Image");
    sf::RenderWindow windowTransformed(sf::VideoMode(size.x, size.y), "Transformed Image");

    sf::Texture textureOriginal, textureTransformed;
    textureOriginal.loadFromImage(originalImage);
    textureTransformed.loadFromImage(image);

    sf::Sprite spriteOriginal, spriteTransformed;
    spriteOriginal.setTexture(textureOriginal);
    spriteTransformed.setTexture(textureTransformed);


    while (windowOriginal.isOpen() || windowTransformed.isOpen()) {
        sf::Event event;

        while (windowOriginal.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowOriginal.close();
        }
        while (windowTransformed.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowTransformed.close();
        }

        if (windowOriginal.isOpen()) {
            windowOriginal.clear(sf::Color::White);
            windowOriginal.draw(spriteOriginal);
            windowOriginal.display();
        }

        if (windowTransformed.isOpen()) {
            windowTransformed.clear(sf::Color::White);
            windowTransformed.draw(spriteTransformed);
            windowTransformed.display();
        }
    }

    if (!image.saveToFile(outputFile)) {
        std::cerr << "Failed to save image: " << outputFile << std::endl;
        return -1;
    }

    return 0;
}
