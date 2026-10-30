class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int countOne = 0;
            int temp = i;
            
            while (temp > 0) {
                if (temp % 2 == 1) {
                    countOne++;
                }
                temp /= 2;
            }
            
            arr[i] = countOne;
        }
        
        return arr;
    }
};