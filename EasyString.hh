#include <sstream>
#include <string>
#include <vector>

namespace easystring {
    const std::string WHITESPACE = " \n\r\t\f\v";

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

    /// Justify the string from the left with `c`, until the whole string reaches length `length`.
    inline std::string left_justify(const std::string& text, char c, int length) {
        int amount = length - text.length();
        if (amount < 1) return text;

        std::ostringstream result;
        for (int i = 0; i < amount; i++) {
            result << c;
        }
        result << text;
        return result.str();
    }

    /// Justify the string from the right with `c`, until the whole string reaches length `length`.
    inline std::string right_justify(const std::string& text, char c, int length) {
        int amount = length - text.length();
        if (amount < 1) return text;

        std::ostringstream result;
        result << text;
        for (int i = 0; i < amount; i++) {
            result << c;
        }
        return result.str();
    }

    /// Removes all whitespace from the left of the string.
    inline std::string trim_left(const std::string& text) {
        size_t start = text.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : text.substr(start);
    }

    /// Removes all whitespace from the right of the string.
    inline std::string trim_right(const std::string& text) {
        size_t end = text.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : text.substr(0, end + 1);
    }

    /// Removes all leading and trailing whitespace from the string.
    inline std::string trim(const std::string& text) {
        return trim_left(trim_right(text));
    }

    /// Reverses a string.
    inline std::string reverse(const std::string& text) {
        std::ostringstream result;
        for (int i = text.length() - 1; i >= 0; i--) {
            result << text[i];
        }
        return result.str();
    }

    /// Returns true if `text` starts with `prefix`.
    inline bool starts_with(const std::string& text, const std::string& prefix) {
        return text.find(prefix) == 0;
    }

    /// Returns true if `text` ends with `prefix`
    inline bool ends_with(const std::string& text, const std::string& suffix) {
        if (suffix.length() > text.length()) return false;
        return text.compare(text.length() - suffix.length(), suffix.length(), suffix) == 0;
    }

    /// Returns true if `text` contains `other`.
    inline bool contains(const std::string& text, const std::string& other) {
        return text.find(other) != std::string::npos;
    }

    /// Returns true if all characters in `text` are uppercase.
    inline bool is_upper(const std::string& text) {
        for (int i = 0; i < text.length(); i++) {
            if (!isupper(text[i])) return false;
        }
        return true;
    }

    /// Returns true if all characters in `text` are lowercase.
    inline bool is_lower(const std::string& text) {
        for (int i = 0; i < text.length(); i++) {
            if (!islower(text[i])) return false;
        }
        return true;
    }

    /// Replace all occurences of `from` with `to` in `text`.
    inline std::string replace(std::string text, const std::string& from, const std::string& to) {
        size_t pos = 0;
        while ((pos = text.find(from, pos)) != std::string::npos) {
            text.replace(pos, from.length(), to);
            pos += to.length();
        }
        return text;
    }
}