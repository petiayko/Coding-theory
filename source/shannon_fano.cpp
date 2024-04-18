#include "../include/shannon_fano.hpp"

Shannon_Fano::~Shannon_Fano() {
    _alp_size = 0;
    _codes.clear();
    delete[] _table;
}

[[nodiscard]] std::string Shannon_Fano::encode(const std::string &plain_text, bool silent = false) noexcept {
    if (plain_text.empty()) {
        if (!silent) {
            std::cout << "Input string is empty" << std::endl;
        }
        return {};
    }

    std::map<char, int> freqs;
    unsigned total = 0;
    for (const auto &ch: plain_text) {
        freqs[ch]++;
        total++;
    }
    _alp_size = (int) freqs.size();

    _table = new SFNode[_alp_size];
    auto f_total = float(total);
    int i;
    std::map<char, int>::iterator fi;
    for (fi = freqs.begin(), i = 0; fi != freqs.end(); ++fi, ++i) {
        _table[i].ch = fi->first;
        _table[i].p = float(fi->second) / f_total;
    }
    qsort(_table, _alp_size, sizeof(SFNode), [](const void *elem1, const void *elem2) {
        const SFNode a = *(SFNode *) elem1;
        const SFNode b = *(SFNode *) elem2;
        if (a.p < b.p) {
            return 1;
        } else if (a.p > b.p) {
            return -1;
        }
        return 0;
    });

    _encode(0, _alp_size - 1);

    if (!silent) {
        for (i = 0; i < _alp_size; i++) {
            std::cout << _table[i].ch << '\t' << _table[i].p << '\t' << _codes[_table[i].ch].c_str() << std::endl;
        }
        std::cout << "\nAlphabet size: " << _alp_size << "\n" << std::endl;
    }

    std::string result;
    for (const auto &ch: plain_text) {
        result += _codes[ch];
    }

    return result;
}

[[nodiscard]] std::string Shannon_Fano::encode(const std::string &plain_text) noexcept {
    return Shannon_Fano::encode(plain_text, false);
}

void Shannon_Fano::encode_file(const std::string &input_filename, const std::string &output_filename, bool silent) noexcept {
    _get_file_to_write(output_filename) << encode(_get_file_data(input_filename), silent);
}

void Shannon_Fano::encode_file(const std::string &input_filename, const std::string &output_filename) noexcept {
    encode_file(input_filename, output_filename, false);
}

[[nodiscard]] std::string Shannon_Fano::encode_file(const std::string &input_filename, bool silent) noexcept {
    return encode(_get_file_data(input_filename), silent);
}

[[nodiscard]] std::string Shannon_Fano::encode_file(const std::string &input_filename) noexcept {
    return encode_file(input_filename, false);
}

void Shannon_Fano::_encode(int li, int ri) {
    if (li == ri) {
        return;
    } else if (ri - li == 1) {
        _codes[_table[li].ch] += '0';
        _codes[_table[ri].ch] += '1';
    } else {
        float pfull = 0;
        for (int i = li; i <= ri; ++i) {
            pfull += _table[i].p;
        }

        float p = 0;
        int isp = -1;
        float phalf = pfull * 0.5f;
        for (int i = li; i <= ri; ++i) {
            p += _table[i].p;
            if (p <= phalf) {
                _codes[_table[i].ch] += '0';
            } else {
                _codes[_table[i].ch] += '1';
                if (isp < 0) {
                    isp = i;
                }
            }
        }

        if (isp < 0) {
            isp = li + 1;
        }

        _encode(li, isp - 1);
        _encode(isp, ri);
    }
}

[[nodiscard]] inline std::string Shannon_Fano::_get_file_data(const std::string &filename) {
    std::string line;
    std::string data;
    auto file = _get_file_to_read(filename);
    while (getline(file, line)) {
        data += line;
    }
    return data;
}

[[nodiscard]] inline std::ifstream Shannon_Fano::_get_file_to_read(const std::string &filename) {
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error{"Unable to open file " + filename};
    }
    return file;
}

[[nodiscard]] inline std::ofstream Shannon_Fano::_get_file_to_write(const std::string &filename) {
    std::ofstream file(filename, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error{"Unable to open file " + filename};
    }
    return file;
}
