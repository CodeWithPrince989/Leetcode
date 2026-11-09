#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        // dp[i][j] stores the max subset size with at most i zeros and j ones
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (const std::string& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            // Update DP table backwards to avoid using the same string multiple times
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = std::max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};