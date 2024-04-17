#include <iostream>

#include "shannon_fano.hpp"

int main() {
    Coder coder;
    std::cout << coder.encode("Laudate Dominum, laudate Dominum, Omnes gentes, alleluia") << std::endl;
    return 0;
}
