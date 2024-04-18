#ifndef CODING_THEORY_HAFFMAN_HPP
#define CODING_THEORY_HAFFMAN_HPP

#include <algorithm>
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

public:
    [[nodiscard]] std::string compress(const std::string&) noexcept;

    void decompress(std::istream &in_stream, std::ostream &out_stream);
};

#endif //CODING_THEORY_HAFFMAN_HPP
