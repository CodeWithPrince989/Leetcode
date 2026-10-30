class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Initialize prevBit with the first bit, and shift n right
        int prevBit = n % 2;
        n /= 2;
        
        while (n > 0) {
            int currentBit = n % 2;
            if (currentBit == prevBit) {
                return false; // Two adjacent bits are the same
            }
            prevBit = currentBit;
            n /= 2;
        }
        return true;
    }
};