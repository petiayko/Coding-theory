#include <iostream>

#include "shannon_fano.hpp"

int main() {
    Coder coder;
    std::cout << coder.encode("Text to encode") << std::endl;
    return 0;
}
