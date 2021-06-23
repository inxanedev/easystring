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

    /// Makes the string lowercase.
    inline std::string lowercase(const std::string& text) {
        std::ostringstream result;
        for (int i = 0; i < text.length(); i++) {
            result << static_cast<char>(tolower(text[i]));
        }
        return result.str();
    }

    /// Puts `amount` of `c` to the left of `text`.
    inline std::string pad_left(const std::string& text, char c, int amount) {
        std::ostringstream result;
        for (int i = 0; i < amount; i++) {
            result << c;
        }
        result << text;
        return result.str();
    }

    /// Puts `amount` of `c` to the right of `text`.
    inline std::string pad_right(const std::string& text, char c, int amount) {
        std::ostringstream result;
        result << text;
        for (int i = 0; i < amount; i++) {
            result << c;
        }
        return result.str();
    }
}