#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int insertIndex = 1; // Position for the next unique element
        
        for (int i = 1; i < nums.size(); i++) {
            // Found a new unique element
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        
        return insertIndex; // 'k', the number of unique elements
    }
};