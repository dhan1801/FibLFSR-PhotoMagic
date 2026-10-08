# FibLFSR PhotoMagic – Image Encryption Tool

A C++ command-line tool that scrambles and unscrambles images with a 16-bit Fibonacci linear feedback shift register (LFSR). It was written for a UMass Lowell computer science course (Section 302) and is an educational project, not a secure cipher.

## How It Works

- **FibLFSR (Part A):** a 16-bit register stored as a binary string. Each `step()` XORs bits 15, 13, 12 and 10, shifts the register left and returns the new bit. `generate(k)` returns the next `k` bits as an integer.
- **PhotoMagic (Part B):** for every pixel, the red, green and blue values are XORed with 8-bit numbers from the LFSR. XOR is reversible, so running the tool again on the output image with the same seed restores the original.
- **Display:** the program opens two SFML windows, one for the original and one for the transformed image, then saves the transformed image to disk.
- **Password support (extra credit):** if the third argument is not a 16-bit binary string, it is treated as a password. The program hashes it with `sum = (sum * 31 + character) mod 2^16` and uses that 16-bit value as the seed, so the same password always gives the same sequence.

## Usage

```
./PhotoMagic input-file.png output-file.png seed-or-password
```

Encrypt:

```
./PhotoMagic photo.png encrypted.png 1011011000110110
```

Decrypt with the same seed or password:

```
./PhotoMagic encrypted.png restored.png 1011011000110110
```

## Project Structure

| File | Purpose |
| --- | --- |
| `FibLFSR.hpp` / `FibLFSR.cpp` | The LFSR class, with input validation (seed must be 16 binary digits). |
| `PhotoMagic.hpp` / `PhotoMagic.cpp` | `transform()` applies the XOR to every pixel. |
| `main.cpp` | Command-line handling, password-to-seed conversion, windows and saving. |
| `test.cpp` | Boost unit tests for the LFSR. |

## Tests

The Boost.Test suite covers `step()`, `generate()`, stream output and invalid input (non-binary seeds, wrong seed length and negative `k`). There are no separate tests for the image transform. It relies on the tested LFSR.

## Requirements

- C++ compiler with C++17 support `[PLACEHOLDER: confirm standard]`
- SFML 2.x
- Boost (unit test framework)

## Build

`[PLACEHOLDER: add your Makefile command or compile line, for example make]`

## Limitations

- The LFSR has a 16-bit state, so it can be broken easily. Do not use this tool to protect sensitive images.
- Hashing passwords into a 16-bit seed leaves only 65,536 possible sequences.
- I have not tested decryption against the original image pixel by pixel. `[PLACEHOLDER: remove this line if you ran a round-trip test]`

## Author

Dhanvika Nakka
