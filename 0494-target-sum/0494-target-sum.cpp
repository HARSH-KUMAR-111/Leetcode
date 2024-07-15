class Solution {
public:
    int func(int ind,vector<int>& nums, int x,vector<vector<int>> &dp){
        if(ind==0){
            if(x==0) return 1;
            return 0;
        }
        if (x < -1000 || x > 1000) {
            return 0; 
        }
        if(dp[ind][x+1000] != -1) return dp[ind][x+1000];
        
        int plus = func(ind-1,nums,x+nums[ind-1],dp);
        int minus = func(ind-1,nums,x-nums[ind-1],dp);

        return dp[ind][x+1000] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));

        return func(n,nums,target,dp);
    }
};