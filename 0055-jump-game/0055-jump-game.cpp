// TC->O(N)
// SC->O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int maxJump =0;
        
        if(n==1) return true;
        if(nums[0] == 0) return false;
        for(int i=0;i<n;i++){
            int currJump = nums[i]+i;

            maxJump = max(maxJump, currJump);

            if(i>=maxJump) return false;
            if(maxJump>=n-1) return true; 
        }

        return true;
    }
};