# FibLFSR PhotoMagic – Image Encryption Tool

A C++ command-line tool that scrambles and unscrambles images using a 16-bit Fibonacci linear feedback shift register (LFSR). It was written for a UMass Lowell computer science course (Section 302) and is an educational project, not a secure cipher.

## How It Works

- **FibLFSR:** a 16-bit register stored as a binary string. Each `step()` XORs bits 15, 13, 12 and 10, shifts the register left, and returns the new bit. `generate(k)` returns the next `k` bits as an integer.
- **PhotoMagic:** for every pixel, the red, green and blue values are each XORed with 8 bits from the LFSR. XOR is reversible, so running the tool on the scrambled image with the same seed restores the original.
- **Display:** the program opens two SFML windows, one showing the original and one showing the transformed image. The transformed image is saved when you close both windows.
- **Password support:** if the third argument is not a 16-bit binary string, it is treated as a password. The program hashes it with `sum = (sum * 31 + character) mod 2^16` and uses the result as the seed, so the same password always gives the same sequence.

## Usage

Build first (see below), then run from the `FibLFSR` folder:

```
./PhotoMagic input-file.png output-file.png seed-or-password
```

Encrypt with a binary seed or a password:

```
./PhotoMagic photo.png scrambled.png 1011011000110110
./PhotoMagic photo.png scrambled.png mypassword
```

Decrypt by running the scrambled image through again with the same seed or password:

```
./PhotoMagic scrambled.png restored.png mypassword
```

Save output as PNG. A lossy format such as JPEG changes pixel values and would break decryption.

## Build

You need `g++`, [SFML](https://www.sfml-dev.org/) (graphics, window and system modules) and the Boost unit test framework.

```
cd FibLFSR
make          # builds PhotoMagic, test and PhotoMagic.a
make clean
```

## Tests

`./test` runs the Boost unit tests for `FibLFSR`. They cover `step()`, `generate()`, stream output, and invalid input (non-binary seeds, wrong seed length and a negative `k`). The image transform has no separate tests and relies on the tested LFSR.

## Project Structure

| File | Purpose |
| --- | --- |
| `FibLFSR/FibLFSR.hpp`, `FibLFSR.cpp` | The LFSR class, which validates that a seed is exactly 16 binary digits. |
| `FibLFSR/PhotoMagic.hpp`, `PhotoMagic.cpp` | `transform()` XORs every pixel with LFSR output. |
| `FibLFSR/main.cpp` | Command-line handling, password-to-seed conversion, the two windows and saving. |
| `FibLFSR/test.cpp` | Boost unit tests. |
| `FibLFSR/Makefile` | Builds with `-std=c++11` and strict warnings. |
| `FibLFSR/Readme-ps1.md` | The original course submission notes. |

## Limitations

- The LFSR has a 16-bit state, and a password is reduced to a 16-bit seed, so there are only 65,536 possible sequences. Do not use this tool to protect sensitive images.

## Author

Dhanvika Nakka
