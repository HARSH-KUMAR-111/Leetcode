// Bit Manipulation
// TC->O(2*N)
// SC->O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr=0;
        for(auto it:nums) xorr^=it;

        int rightmost=(xorr&(xorr-1))^xorr;
        int b1=0,b2=0;
        for(auto it:nums){
            if(it&rightmost) b1^=it;
            else b2^=it;
        }
        return {b1,b2};
    }
};