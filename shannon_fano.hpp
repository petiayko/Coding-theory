#ifndef CODING_THEORY_SHANNON_FANO_HPP
#define CODING_THEORY_SHANNON_FANO_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Node {
    char ch;
    float p;
};

class Coder {
private:
    int _alp_size{};
    Node *_table{};
    std::map<char, std::string> _codes;

public:
    ~Coder();

    [[nodiscard]] std::string encode(const std::string &, bool) noexcept;

    [[nodiscard]] std::string encode(const std::string &) noexcept;

    void encode_file(const std::string &, const std::string &, bool) noexcept;

    void encode_file(const std::string &, const std::string &) noexcept;

    [[nodiscard]] std::string encode_file(const std::string &, bool) noexcept;

    [[nodiscard]] std::string encode_file(const std::string &) noexcept;

private:
    void _encode(int, int);
};

#endif //CODING_THEORY_SHANNON_FANO_HPP
