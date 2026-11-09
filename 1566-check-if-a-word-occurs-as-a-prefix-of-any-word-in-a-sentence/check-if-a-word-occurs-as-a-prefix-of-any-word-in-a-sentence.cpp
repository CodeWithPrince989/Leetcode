#include <string>
#include <sstream>

class Solution {
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord) {
        std::stringstream ss(sentence);
        std::string word;
        int index = 1;
        
        while (ss >> word) {
            // Check if searchWord is a prefix of the current word
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
        return -1;
    }
};