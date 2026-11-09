#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // stores indices of elements
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove elements that are out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // 2. Remove elements from the back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Push the current element's index
            dq.push_back(i);
            
            // 4. Once the first window of size k is reached, record the maximum
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};