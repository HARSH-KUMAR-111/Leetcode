// Bit Manipulation
//TC->O(1)
//SC->O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int tmp=(a&b)<<1;
            a=a^b;
            b=tmp;
        }
        return a;
    }
};