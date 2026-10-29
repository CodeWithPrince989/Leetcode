class Solution {
public:
    string largestOddNumber(string num) {
        // Traverse backwards from the end of the string
        for (int i = num.length() - 1; i >= 0; i--) {
            // Check if the current character represents an odd digit
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from the beginning up to this odd digit
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};