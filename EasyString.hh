#include <sstream>
#include <string>

namespace easystring {
    /// Makes the string uppercase.
    inline std::string uppercase(const std::string& text) {
        std::ostringstream result;
        for (int i = 0; i < text.length(); i++) {
            result << static_cast<char>(toupper(text[i]));
        }
        return result.str();
    }
}