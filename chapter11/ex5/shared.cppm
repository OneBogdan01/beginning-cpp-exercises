export module words:shared;

import std;
namespace words {
export using Words = std::vector<std::shared_ptr<std::string>>;
}