#include <iostream>

#include "include/shannon_fano.hpp"
#include "include/haffman.hpp"

int main() {
    Shannon_Fano sf_coder;
    std::cout << sf_coder.encode("Laudate Dominum, laudate Dominum, Omnes gentes, alleluia") << std::endl;

    std::cout << "\n----------------------------------------------\n" << std::endl;

    Haffman h_coder;
    std::cout << h_coder.compress("Laudate Dominum, laudate Dominum, Omnes gentes, alleluia") << std::endl;

    return 0;
}
