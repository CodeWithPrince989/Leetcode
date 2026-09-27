class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to avoid overflow when converting INT_MIN (-2^31) to positive
        long long N = n;
        
        // Handle negative exponent
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        double current_product = x;
        
        while (N > 0) {
            if (N % 2 == 1) { // If N is odd
                ans *= current_product;
            }
            current_product *= current_product; // Square the base
            N /= 2;                             // Divide exponent by 2
        }
        
        return ans;
    }
};