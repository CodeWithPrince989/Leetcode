class Solution {
public:
    int xorOperation(int n, int start) {
        
        vector<int> nums(n+1, 0);
        for(int i=0; i<n; i++){
            nums[i] = start+2*i;
        }

        int XOR = 0;
        for(int i=0; i<n; i++){
            XOR ^= nums[i];
        }

        return XOR;
    }
};