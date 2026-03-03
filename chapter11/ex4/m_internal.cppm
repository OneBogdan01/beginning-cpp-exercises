module words:internals;

import words;

void swap(Words& words, std::size_t first, std::size_t second) {
    auto temp{words[first]};
    words[first] = words[second];
    words[second] = temp;
}
std::size_t max_word_length(const Words& words) {
    std::size_t max{};
    for (auto& pword : words)
        if (max < pword->length())
            max = pword->length();
    return max;
}
