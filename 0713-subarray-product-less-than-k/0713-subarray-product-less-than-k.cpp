// Sliding Window Problem
// TC->O(N)
// SC->O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1) return 0;
        int i=0,j=0;
        int cnt=0;
        int prod=1;
        while(j<nums.size()){
            prod*=nums[j];
            
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};