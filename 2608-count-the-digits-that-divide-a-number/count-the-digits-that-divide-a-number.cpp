class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int originalNum = num; // Good practice if you want to keep the original number unchanged, 
                               // but since num itself is passed by value, modifying num directly is fine too.
        while(num > 0){
            int digit = num % 10;
            if(digit != 0 && originalNum % digit == 0){ // Note: Constraints say num doesn't contain 0, but it's safe to check
                count++;
            }
            num = num / 10; // This must execute on every iteration!
        }
        return count;
    }
};