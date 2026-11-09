#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maximumSwap(int num) {
        std::string s = std::to_string(num);
        int n = s.length();
        
        // Store the last occurrence index of each digit (0-9)
        std::vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        
        // Traverse the string from left to right to find the first place to improve
        for (int i = 0; i < n; ++i) {
            // Check if there is a larger digit that appears later in the string
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap and return the result immediately
                    std::swap(s[i], s[last[d]]);
                    return std::stoi(s);
                }
            }
        }
        
        return num;
    }
};