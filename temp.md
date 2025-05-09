| **Function / Operation**                        | **Short Syntax (C++)**                                                       |
|-------------------------------------------------|------------------------------------------------------------------------------|
| Set the `n`-th bit to 1                         | `num |= (1 << n);`                                                            |
| Clear the `n`-th bit (set to 0)                 | `num &= ~(1 << n);`                                                           |
| Toggle the `n`-th bit                          | `num ^= (1 << n);`                                                            |
| Check if the `n`-th bit is set (1)              | `if (num & (1 << n)) { /* bit is set */ }`                                     |
| Check if the `n`-th bit is cleared (0)          | `if (!(num & (1 << n))) { /* bit is not set */ }`                             |
| Count the number of set bits (Hamming weight)   | `int countSetBits(int num) { int count = 0; while (num) { num &= (num - 1); count++; } return count; }` |
| Find the highest set bit (most significant bit) | `int highestSetBit = log2(num & -num);`                                        |
| Reverse the bits of a number                    | `unsigned int reverseBits(unsigned int n) { unsigned int reverse = 0; while (n) { reverse = (reverse << 1) | (n & 1); n >>= 1; } return reverse; }` |
| Check if a number is a power of 2               | `bool isPowerOfTwo(int num) { return (num && !(num & (num - 1))); }`         |
| Swap two numbers without a temporary variable   | `a ^= b; b ^= a; a ^= b;`                                                     |
| Get the rightmost set bit                       | `int rightmostSetBit = num & -num;`                                           |
| Clear all bits after the `n`-th bit (inclusive) | `num &= (1 << n) - 1;`                                                       |
| Set all bits after the `n`-th bit (inclusive)   | `num |= (~0 << n);`                                                           |
| Toggle all bits                                 | `num = ~num;`                                                                 |
| Add 1 to the number (using two's complement)    | `num = num + 1;` or `num = -(-num);`                                          |
| Get the number of bits required to represent a number | `int bitCount(int num) { return (num == 0) ? 1 : (int)(log2(num)) + 1; }`     |
