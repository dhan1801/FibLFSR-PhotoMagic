// Copyright 2025 Dhanvika Nakka
#include "FibLFSR.hpp"
#include <stdexcept>
#include <string>

namespace PhotoMagic {

FibLFSR::FibLFSR(std::string seed) {
    if (seed.length() != 16) {
        throw std::invalid_argument("Seed must be exactly 16 bits long");
    }
    for (char c : seed) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Seed must contain only binary digits");
        }
    }
    reg = seed;
}

int FibLFSR::step() {
    int bit13 = reg[2] - '0';
    int bit12 = reg[3] - '0';
    int bit10 = reg[5] - '0';
    int bit15 = reg[0] - '0';
    int newBit = bit15 ^ bit13 ^ bit12 ^ bit10;
    reg = reg.substr(1) + std::to_string(newBit);
    return newBit;
}

int FibLFSR::generate(int k) {
    if (k < 0) {
        throw std::invalid_argument("k must be a non-negative integer");
    }
    int result = 0;
    for (int i = 0; i < k; ++i) {
        result = (result << 1) | step();
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    out << lfsr.reg;
    return out;
}

}  // namespace PhotoMagic
