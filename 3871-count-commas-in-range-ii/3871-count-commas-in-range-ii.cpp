class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long threshold = 1000; // 10^3

        while (n >= threshold) {
            ans += (n - threshold + 1);
            
            // Avoid overflow when threshold * 1000 exceeds long long limit
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }

        return ans;
    }
};