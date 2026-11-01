class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if (nums[l] <= nums[mid]) {
                // Check if the target lies within the sorted left half
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Search left
                } else {
                    l = mid + 1; // Search right
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if the target lies within the sorted right half
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Search right
                } else {
                    r = mid - 1; // Search left
                }
            }
        }
        return -1;
    }
};