class Solution {
public:
    int hammingWeight(int n) {
        
        int countOne = 0;
        while(n>0){
            int digit = n%2;
            if(digit==1){
                countOne++;
            }
            n=n/2;
        }
        return countOne;
    }
};