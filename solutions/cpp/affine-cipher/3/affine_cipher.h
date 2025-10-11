#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H
#include <string>
namespace affine_cipher {

// TODO: add your solution here
    std::string encode(const std::string text, const int a, const int b);
    std::string decode(const std::string code, const int a, const int b);

}  // namespace affine_cipher

#endif  // AFFINE_CIPHER_H
