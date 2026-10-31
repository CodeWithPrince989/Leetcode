class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        // If the single element is at the very end of the array
        return nums[n - 1];
    }
};