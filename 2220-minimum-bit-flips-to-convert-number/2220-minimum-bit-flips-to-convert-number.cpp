// TC->O(logn)
// SC->O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start^goal;
            
        int cnt=0;
        while(xorr>0){
            cnt+= xorr&1;
            xorr>>=1;
        }
        return cnt;
    }
};