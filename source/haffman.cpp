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


[[nodiscard]] std::string Haffman::compress(const std::string& plain_text) noexcept {
    for (const auto& ch: plain_text) {
        char_map[ch]++;
    }

    auto *tree = build_char_tree();
    build_code_table(tree);

    for (const auto& i: code_table) {
        std::cout << i.first << '\t' << char_map[i.first] << '\t';
        for (auto j: i.second) {
            std::cout << j;
        }
        std::cout << std::endl;
    }

    std::cout << "\nAlphabet size: " << char_map.size() << std::endl;

    std::string encoded_text;
    for (const auto& ch : plain_text) {
        for (auto bit : code_table[ch]) {
            encoded_text += std::to_string(bit);
        }
    }

    return encoded_text;
}

//void Haffman::decompress(std::istream &in_stream, std::ostream &out_stream) {
//    unsigned long char_map_size;
//    in_stream >> char_map_size;
//    std::cout << "char map size: " << char_map_size << std::endl;
//    for (unsigned long i = 0; i < char_map_size; ++i) {
//        char symbol;
//        size_t count;
//        in_stream.get(symbol);
//        in_stream >> count;
//        char_map[symbol] = count;
//        std::cout << symbol << ": " << count << std::endl;
//    }
//
//    auto *node = build_char_tree();
//
//    // decode compressed data
//    short count = 0;
//    auto *it_node = node;
//    char byte;
//    in_stream.get(byte);
//
//    do {
//        bool bit = (bool) (byte & (1 << (7 - count)));
//        it_node = bit ? it_node->right_node : it_node->left_node;
//        if (it_node->left_node == nullptr && it_node->right_node == nullptr) {
//            out_stream << it_node->letter;
//            it_node = node;
//        }
//
//        count++;
//        if (count == 8) {
//            count = 0;
//            in_stream.get(byte);
//        }
//    } while (!in_stream.eof());
//}
