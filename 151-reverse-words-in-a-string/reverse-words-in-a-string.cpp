#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        
        // Extract all words individually
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Rebuild the string in reverse order
        std::string result = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i > 0) {
                result += " ";
            }
        }
        
        return result;
    }
};