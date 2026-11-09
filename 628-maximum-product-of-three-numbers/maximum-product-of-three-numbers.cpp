#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array to easily access smallest and largest elements
        std::sort(nums.begin(), nums.end());
        
        // Option 1: Product of the three largest numbers
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        // Option 2: Product of the two smallest (negative) numbers and the largest number
        int option2 = nums[0] * nums[1] * nums[n - 1];
        
        return std::max(option1, option2);
    }
};