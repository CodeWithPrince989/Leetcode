class Solution {
public:
    string reverseParentheses(string s) {
        while (true) {
            size_t right = s.find(')');
            if (right == string::npos) break; // No more brackets left
            
            size_t left = s.rfind('(', right); // Find closest '(' before ')'
            
            // Extract and reverse the innermost substring
            string inner = s.substr(left + 1, right - left - 1);
            reverse(inner.begin(), inner.end());
            
            // Replace (inner) with inner reversed
            s.replace(left, right - left + 1, inner);
        }
        return s;
    }
};