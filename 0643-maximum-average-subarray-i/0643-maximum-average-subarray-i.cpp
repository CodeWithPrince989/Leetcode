class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }

        double max_sum = current_sum;

        for (int i = k; i < nums.size(); i++) {
            current_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, current_sum);
        }
        return max_sum / k;
    }
};