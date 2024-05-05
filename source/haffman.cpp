#include "../include/haffman.hpp"

HNode::HNode(HNode *left, HNode *right) : left_node(left), right_node(right) {
    count = left->count + right->count;
    letter = '\0';
}

HNode::HNode(size_t count, char letter) : count(count), letter(letter) {
    left_node = right_node = nullptr;
}

HNode::~HNode() {
    delete left_node;
    delete right_node;
}

bool operator<(const HNode &left, const HNode &right) {
    if (left.count == right.count) {
        return left.letter < right.letter;
    }
    return left.count < right.count;
}

bool HNode::compare(const HNode *a, const HNode *b) {
    return (*a) < (*b);
}

HNode *Haffman::build_char_tree() {
    std::list<HNode *> tree;

    for (auto pair: char_map) {
        tree.push_back(new HNode(pair.second, pair.first));
    }

    while (tree.size() != 1) {
        tree.sort(HNode::compare);

        HNode *left = tree.front();
        tree.pop_front();

        HNode *right = tree.front();
        tree.pop_front();

        tree.push_back(new HNode(left, right));
    }

    return tree.front();
}

void Haffman::build_code_table(HNode *node) {
    if (node->left_node != nullptr) {
        code.push_back(false);
        build_code_table(node->left_node);
    }
    if (node->right_node != nullptr) {
        code.push_back(true);
        build_code_table(node->right_node);
    }
    if (node->letter != '\0') {
        code_table[node->letter] = code;
    }

    code.pop_back();
}

[[nodiscard]] std::string Haffman::compress(const std::string &plain_text, bool silent) noexcept {
    for (const auto &ch: plain_text) {
        char_map[ch]++;
    }

    auto *tree = build_char_tree();
    build_code_table(tree);

    if (!silent) {
        for (const auto &i: code_table) {
            std::cout << i.first << '\t' << char_map[i.first] << '\t';
            for (auto j: i.second) {
                std::cout << j;
            }
            std::cout << std::endl;
        }

        std::cout << "\nAlphabet size: " << char_map.size() << std::endl;
    }

    std::string encoded_text;
    for (const auto &ch: plain_text) {
        for (auto bit: code_table[ch]) {
            encoded_text += std::to_string(bit);
        }
    }

    return encoded_text;
}

[[nodiscard]] std::string Haffman::compress(const std::string &plain_text) noexcept {
    return compress(plain_text, false);
}

void
Haffman::compress_file(const std::string &input_filename, const std::string &output_filename, bool silent) noexcept {
    _get_file_to_write(output_filename) << compress(_get_file_data(input_filename), silent);
}

void Haffman::compress_file(const std::string &input_filename, const std::string &output_filename) noexcept {
    compress_file(input_filename, output_filename, false);
}

[[nodiscard]] std::string Haffman::compress_file(const std::string &input_filename, bool silent) noexcept {
    return compress(_get_file_data(input_filename), silent);
}

[[nodiscard]] std::string Haffman::compress_file(const std::string &input_filename) noexcept {
    return compress_file(input_filename, false);
}

[[nodiscard]] inline std::string Haffman::_get_file_data(const std::string &filename) {
    std::string line;
    std::string data;
    auto file = _get_file_to_read(filename);
    while (getline(file, line)) {
        data += line;
    }
    return data;
}

[[nodiscard]] inline std::ifstream Haffman::_get_file_to_read(const std::string &filename) {
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error{"Unable to open file " + filename};
    }
    return file;
}

[[nodiscard]] inline std::ofstream Haffman::_get_file_to_write(const std::string &filename) {
    std::ofstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error{"Unable to open file " + filename};
    }
    return file;
}
