
# PS1: LFSR / PhotoMagic

## Contact
Name: Dhanvika Nakka
Section: 302
Time to Complete: 11 hours

## Description
This project implements a 16-bit Fibonacci Linear Feedback Shift Register (FibLFSR) to generate pseudo-random bits, developed in Part A. In Part B, the FibLFSR is used in the PhotoMagic program to encrypt and decrypt digital images using pseudo-random bit sequences.

### Features
The FibLFSR from Part A uses a 16-bit binary string for bit-shifting and XOR operations. For Part B, PhotoMagic takes an input image, output filename, and either a binary seed or alphanumeric password via command-line arguments. It transforms the image by XORing pixel color values with 8-bit LFSR outputs, displays both original and transformed images in separate windows, and saves the result.

#### Part a
- Implemented FibLFSR constructor with error checks.
- Implemented step() and generate(k) functions.
- Included a demo main.cpp and thorough Boost unit tests.

#### Part b
- Created PhotoMagic namespace with transform() for image encryption/decryption.
- Updated main.cpp to process command-line inputs and show two SFML windows.
- Applied transformation to the entire image, not just a 200x200 section.
- Displays both the original and transformed images in separate SFML windows.
- Applies encryption to the entire image, not just a section.
- Saves the transformed image to disk.

### Issues
No issues.

### Tests
Reused Part A’s Boost unit tests. No new tests were added for Part B, as the transform function relies on the validated FibLFSR.

### Extra Credit
This project supports using alphanumeric passwords in place of 16-bit binary seeds.
 Password-to-Seed Conversion(ex:abc123)
If the third command-line argument is not a 16-bit binary string, it is treated as a password. The conversion process is:
1. Sum the ASCII values of the password's characters.
2. Take the result modulo 2^16 (65536).
3. Convert that value into a 16-bit binary string.
4. Use that binary string to initialize the FibLFSR.

This ensures that the same password always results in the same encryption/decryption sequence, supporting repeatable transformations.


### Encryption Process 
The program encrypts each pixel’s red, green, and blue values by XORing them with 8-bit numbers from the FibLFSR. XOR is reversible: XORing a pixel value with an LFSR value and then again with the same value (using the same seed) restores the original. The FibLFSR ensures the same sequence for a given seed, enabling decryption. A different seed produces a different sequence, preventing proper decryption.



## Acknowledgements
I have used the PDFs provided by the professor and the pixels.cpp starter code.

### Credits
No external images were used.