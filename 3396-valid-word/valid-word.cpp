#include <string>
#include <cctype>

class Solution {
public:
    bool isValid(std::string word) {
        // Condition 1: Minimum length of 3 characters
        if (word.length() < 3) {
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            // Condition 2: Must contain only digits or English letters
            if (!std::isalnum(c)) {
                return false;
            }

            // Check if character is a vowel or consonant (if it's a letter)
            if (std::isalpha(c)) {
                char lower = std::tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        // Condition 3 & 4: Must have at least one vowel and one consonant
        return hasVowel && hasConsonant;
    }
};