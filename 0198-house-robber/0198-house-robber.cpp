//Memoization
//TC-> O(N)
//SC-> O(N)+O(N) 
class Solution {
public:
    int func(vector<int> &nums, vector<int> &dp,int ind){
        if(ind<0) return 0;
        if(ind==0) return nums[0];

        if(dp[ind]!=-1) return dp[ind];
        int pick=INT_MIN;
        if(ind>=1)
            pick= nums[ind]+func(nums,dp,ind-2);
        int notpick =0+func(nums,dp,ind-1);

        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        return func(nums,dp,n-1);

    }
};