#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1, missing = -1;
        
        sort(nums.begin(), nums.end());
        
        // Check for duplicate and missing numbers
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                duplicate = nums[i];
            }
        }
        
        // To find missing, we can check which number from 1 to n is absent
        // (Alternatively, use a frequency array or hash set)
        vector<int> count(n + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) duplicate = i;
            if (count[i] == 0) missing = i;
        }
        
        return {duplicate, missing};
    }
};