#include <chrono>
#include <iostream>
#include <ratio>

#include "include/shannon_fano.hpp"
#include "include/haffman.hpp"

typedef std::pair<size_t, double> statistic;

std::string generate(size_t len) {
    std::string alphabet = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM-*+=";
    std::string res;
    for (auto i = 0; i < len; i++) {
        res += alphabet[rand() % alphabet.size()];
    }
    return res;
}

std::pair<statistic, statistic> get_stat(const std::string &data) {
    std::pair<statistic, statistic> result;

    Shannon_Fano sf_coder;
    std::chrono::high_resolution_clock::time_point beg = std::chrono::high_resolution_clock::now();
    auto compressed = sf_coder.encode(data, true);
    std::chrono::high_resolution_clock::time_point ed = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = ed - beg;
    result.first = std::make_pair(compressed.size(), duration.count());
    compressed.clear();

    Haffman h_coder;
    beg = std::chrono::high_resolution_clock::now();
    compressed = h_coder.compress(data, true);
    ed = std::chrono::high_resolution_clock::now();
    duration = ed - beg;
    result.second = std::make_pair(compressed.size(), duration.count());

    return result;
}

int main() {
    std::cout << "Shannon Fano\t\tHaffman" << std::endl;
    for (size_t i = 10; i < 10000; i *= 10) {
        auto stat = get_stat(generate(i));
        std::cout << i << '\t' << stat.first.first << '\t' << stat.first.second << '\t' <<
                  stat.second.first << '\t' << stat.second.second << std::endl;
    }

    return 0;
}
