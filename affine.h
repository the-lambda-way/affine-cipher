#pragma once

#include <array>
#include <string>
#include <string_view>


std::string_view alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


// ---------------------------------------------------------------------------------------------------------------------
// Encryption
// ---------------------------------------------------------------------------------------------------------------------
int affine (int a, int b, int ordinal)
{
     return (a * ordinal + b) % 26;
}


char affine (int a, int b, char c)
{
     return affine(a, b, c - 'A') + 'A';
}


template <std::size_t N>
void affine_in_place (int a, int b, std::array<int, N>& ordinals)
{
     for (int& o : ordinals)     o = affine(a, b, o);
}


void affine_in_place (int a, int b, std::string& str)
{
     for (char& c : str)     c = affine(a, b, c);
}


template <std::size_t N>
std::array<int, N> affine (int a, int b, std::array<int, N> ordinals)
{
     affine_in_place(a, b, ordinals);
     return ordinals;
}


std::string affine (int a, int b, std::string_view str)
{
     std::string out;
     out.reserve(str.size());

     for (char c : str)     out.push_back(affine(a, b, c));

     return out;
}


template <std::size_t N>
std::array<std::array<int, N>, 312> all_affines (const std::array<int, N>& ordinals)
{
     std::array<std::array<int, N>, 312> out;
     constexpr int coprimes[12] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

     for (int a = 0; a < 12; ++a)
          for (int b = 0; b < 26; ++b)
               out[26 * a + b] = affine(coprimes[a], b, ordinals);

     return out;
}


std::array<std::string, 312> all_affines (std::string_view str)
{
     std::array<std::string, 312> out;
     constexpr int coprimes[12] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

     for (int a = 0; a < 12; ++a)
          for (int b = 0; b < 26; ++b)
               out[26 * a + b] = affine(coprimes[a], b, str);

     return out;
}


// ---------------------------------------------------------------------------------------------------------------------
// Decryption
// ---------------------------------------------------------------------------------------------------------------------
int decrypt_affine (int inverse_a, int b, int ordinal)
{
     // Minimum possible normalized value is -625 for inverse_a = 25, b = 25, ordinal = 0. Next multiple of 26 is 650.
     return (inverse_a * (ordinal - b) + 650) % 26;
}


char decrypt_affine (int inverse_a, int b, char c)
{
     return decrypt_affine(inverse_a, b, c - 'A') + 'A';
}


template <std::size_t N>
void decrypt_affine_in_place (int a, int b, std::array<int, N>& ordinals)
{
     for (int& o : ordinals)     o = decrypt_affine(a, b, o);
}


void decrypt_affine_in_place (int a, int b, std::string& str)
{
     for (char& c : str)     c = decrypt_affine(a, b, c);
}


template <std::size_t N>
std::array<int, N> decrypt_affine (int a, int b, std::array<int, N> ordinals)
{
     decrypt_affine_in_place(a, b, ordinals);
     return ordinals;
}


std::string decrypt_affine (int a, int b, std::string_view str)
{
     std::string out;
     out.reserve(str.size());

     for (char c : str)     out.push_back(decrypt_affine(a, b, c));

     return out;
}


template <std::size_t N>
std::array<std::array<int, N>, 312> decrypt_all_affines (const std::array<int, N>& ordinals)
{
     std::array<std::array<int, N>, 312> out;
     constexpr int inverse_primes[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

     for (int a = 0; a < 12; ++a)
          for (int b = 0; b < 26; ++b)
               out[26 * a + b] = decrypt_affine(inverse_primes[a], b, ordinals);

     return out;
}


std::array<std::string, 312> decrypt_all_affines (std::string_view str)
{
     std::array<std::string, 312> out;
     constexpr int inverse_primes[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

     for (int a = 0; a < 12; ++a)
          for (int b = 0; b < 26; ++b)
               out[26 * a + b] = decrypt_affine(inverse_primes[a], b, str);

     return out;
}

