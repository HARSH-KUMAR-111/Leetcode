//Bit Manipulation
// TC-> O((log n)^2)
// SC-> O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;

        if(dividend >=0 && divisor <0) sign=false;
        else if(dividend <0 && divisor >0) sign =false;
        long ans=0;
        long num=abs(dividend);
        long d=abs(divisor);
        divisor= abs(divisor);
        while(num>=d){
            long cnt=0;

            while(num>=(d<<(cnt+1))){
                cnt++;
            }
            ans+=(1<<cnt);
            num-=(d<<cnt);
        }
        if(ans==(1<<31) && sign) return INT_MAX;

        if(ans==(1<<31) && !sign) return INT_MIN;

        return sign? ans:(-1*ans);
    }
};