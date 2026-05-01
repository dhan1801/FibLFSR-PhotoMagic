// Copyright 2025 Dhanvika Nakka
#ifndef FIBLFSR_HPP
#define FIBLFSR_HPP

#include <string>
#include <iostream>

namespace PhotoMagic {

class FibLFSR {
 public:
    explicit FibLFSR(std::string seed);
    int step();
    int generate(int k);
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr);

 private:
    std::string reg;
};

}   // namespace PhotoMagic

#endif
