# Affine Cipher Decryptor

Encrypts or decrypts texts with the affine cipher. The [affine cipher](https://en.wikipedia.org/wiki/Affine_cipher) is a simple substitution cipher which shifts each letter using the formula ``(a*c + b) mod 26`` for a letter ``c`` and integer values ``a`` and ``b``.


# Usage
Drop the header into your program folder and ``#include`` in your program.

The following functions are provided:

*affine:* Encrypt a single letter or character ordinal, or string or array of ordinals.
*affine_in_place:* Encrypt a string or array of ordinals into an existing object.
*all_affines:* Encrypt a string or array of ordinals with all invertible values of ``a`` and all values of ``b``, both variables between 0 to 26.
*decrypt_affine:* Decrypt a single letter or character ordinal, or string or array of ordinals.
*decrypt_affine_in_place:* Decrypt a string or array of ordinals into an existing object.
*decrypt_all_affines:* Decrypt a string or array of ordinals with all the coprimes of the invertible values of ``a`` and all values of ``b``, both variables between 0 to 26.


# Notes
Pass the standard alphabet into ``all_affines`` or ``decrypt_all_affines`` to get a lookup table for every valid combination of settings and letters. However, I tested the performance of using a lookup table to encrypt a string millions of times vs regenerating the encryptions every time, and the running time was identical on my machine (Core i7-6500u, 2.50GHz, 16GB DDR3). Thus, I did not include any lookup tables or retrieval algorithms in the library.


# License

Copyright (c) 2020 Mike Castillo under the [MIT License](https://choosealicense.com/licenses/mit/). See LICENSE for the full terms.