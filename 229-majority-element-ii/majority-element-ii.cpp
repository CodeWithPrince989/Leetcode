#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int count1 = 0, count2 = 0;
        long long cand1 = -3e9, cand2 = -3e9; // Using a value out of constraints bounds
        
        // Phase 1: Find potential candidates
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Phase 2: Verify the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
        
        std::vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(cand1);
        if (count2 > threshold) result.push_back(cand2);
        
        return result;
    }
};