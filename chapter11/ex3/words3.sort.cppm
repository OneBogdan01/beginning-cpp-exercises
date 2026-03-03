export module words3.sort;

import std;
import words3.utils;

namespace words3::sort {

void swap(Words& words, std::size_t first, std::size_t second);
void sort(Words& words, std::size_t start, std::size_t end);
export void sort(Words& words);

void swap(Words& words, std::size_t first, std::size_t second) {
    auto temp{words[first]};
    words[first] = words[second];
    words[second] = temp;
}
//implementation
void sort(Words& words, std::size_t start, std::size_t end) {
    // start index must be less than end index for 2 or more elements
    if (!(start < end))
        return;

    // Choose middle address to partition set
    swap(words, start, (start + end) / 2); // Swap middle address with start

    // Check words against chosen word
    std::size_t current{start};
    for (std::size_t i{start + 1}; i <= end; i++) {
        if (*words[i] < *words[start]) // Is word less than chosen word?
            swap(words, ++current, i); // Yes, so swap to the left
    }

    swap(words, start, current); // Swap chosen and last swapped words

    if (current > start)
        sort(words, start, current - 1); // Sort left subset if exists
    if (end > current + 1)
        sort(words, current + 1, end); // Sort right subset if exists
}

// Sort strings in ascending sequence
void sort(Words& words) {
    if (!words.empty())
        sort(words, 0, words.size() - 1);
}

} // namespace words3::sort