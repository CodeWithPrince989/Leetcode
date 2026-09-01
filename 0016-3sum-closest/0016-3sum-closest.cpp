#include <vector>
#include <cmath>
#include <cstdlib>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        // Initialize with the sum of the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int currentSum = nums[i] + nums[j] + nums[k];
                    
                    // If current sum is closer to target than closestSum, update it
                    if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                        closestSum = currentSum;
                    }
                }
            }
        }
        
        return closestSum;
    }
};