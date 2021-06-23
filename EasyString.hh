#include <sstream>
#include <string>
#include <vector>

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

    /// Transforms a string into the title case.
    inline std::string title_case(const std::string& text) {
        std::ostringstream result;
        
        std::istringstream iss(text);
        do {
            std::string word;
            std::ostringstream transformed_word;
            iss >> word;
            for (int i = 0; i < word.length(); i++) {
                if (i == 0) transformed_word << static_cast<char>(toupper(word[0]));
                else transformed_word << static_cast<char>(tolower(word[i]));
            }
            result << transformed_word.str() << ' ';
        } while (iss);

        std::string to_trim = result.str();
        return to_trim.substr(0, to_trim.length() - 1);
    }

    /// Split a string into a list of strings, using a string delimiter.
    inline std::vector<std::string> split(std::string text, const std::string& delim) {
        std::vector<std::string> result;
        size_t pos = 0;
        std::string token;
        while ((pos = text.find(delim)) != std::string::npos) {
            token = text.substr(0, pos);
            result.push_back(token);
            text.erase(0, pos + delim.length());
        }
        result.push_back(text);
        return result;
    }
}