export words3.utils;

namespace words3::utils {
void swap(Words& words, std::size_t first, std::size_t second);

std::size_t max_word_length(const Words& words);
namespace words {

export Words extract_words(const std::string& text, const std::string& separators);
export void print_words(const Words& words);
}