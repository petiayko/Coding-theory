#ifndef CODING_THEORY_SHANNON_FANO_HPP
#define CODING_THEORY_SHANNON_FANO_HPP

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct SFNode {
    char ch;
    float p;
};

class Shannon_Fano {
private:
    int _alp_size{};
    SFNode *_table{};
    std::map<char, std::string> _codes;

public:
    ~Shannon_Fano();

    [[nodiscard]] std::string encode(const std::string &, bool) noexcept;

    [[nodiscard]] std::string encode(const std::string &) noexcept;

    void encode_file(const std::string &, const std::string &, bool) noexcept;

    void encode_file(const std::string &, const std::string &) noexcept;

    [[nodiscard]] std::string encode_file(const std::string &, bool) noexcept;

    [[nodiscard]] std::string encode_file(const std::string &) noexcept;

private:
    void _encode(int, int);

    [[nodiscard]] inline static std::string _get_file_data(const std::string &);

    [[nodiscard]] inline static std::ifstream _get_file_to_read(const std::string &);

    [[nodiscard]] inline static std::ofstream _get_file_to_write(const std::string &);
};

#endif //CODING_THEORY_SHANNON_FANO_HPP
