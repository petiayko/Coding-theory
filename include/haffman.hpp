#ifndef CODING_THEORY_HAFFMAN_HPP
#define CODING_THEORY_HAFFMAN_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

struct HNode {
    size_t count;
    char letter;
    HNode *left_node;
    HNode *right_node;

    HNode(HNode *, HNode *);

    HNode(size_t, char);

    ~HNode();

    friend bool operator<(const HNode &, const HNode &);

    static bool compare(const HNode *, const HNode *);
};

class Haffman {
public:
    [[nodiscard]] std::string compress(const std::string &, bool) noexcept;

    [[nodiscard]] std::string compress(const std::string &) noexcept;

    void compress_file(const std::string &, const std::string &, bool) noexcept;

    void compress_file(const std::string &, const std::string &) noexcept;

    [[nodiscard]] std::string compress_file(const std::string &, bool) noexcept;

    [[nodiscard]] std::string compress_file(const std::string &) noexcept;

private:
    typedef std::unordered_map<char, size_t> char_map_t;
    typedef std::vector<bool> code_t;
    typedef std::unordered_map<char, code_t> code_table_t;

    std::stringstream input;
    char_map_t char_map;
    code_t code;
    code_table_t code_table;

    HNode *build_char_tree();

    void build_code_table(HNode *node);

    [[nodiscard]] inline static std::string _get_file_data(const std::string &);

    [[nodiscard]] inline static std::ifstream _get_file_to_read(const std::string &);

    [[nodiscard]] inline static std::ofstream _get_file_to_write(const std::string &);
};

#endif //CODING_THEORY_HAFFMAN_HPP
