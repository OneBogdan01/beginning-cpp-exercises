export module words2;
import std;

export using Words = std::vector<std::shared_ptr<std::string>>;
void swap(Words& words, std::size_t first, std::size_t second);
void sort(Words& words, std::size_t start, std::size_t end);
std::size_t max_word_length(const Words& words);
namespace words {


export void sort(Words& words);
export Words extract_words(const std::string& text, const std::string& separators);
export void print_words(const Words& words);



} // namespace words

export namespace wrds = words;
namespace w {
    export using namespace words;
}