#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Step 1: Store key-value pairs in a hash map
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        int i = 0;

        // Step 2: Iterate through string s
        while (i < n) {
            if (s[i] == '(') {
                i++; // Skip '('
                string key = "";
                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }
                i++; // Skip ')'

                // Check if key exists in dictionary
                if (dict.count(key)) {
                    result += dict[key];
                } else {
                    result += '?';
                }
            } else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};