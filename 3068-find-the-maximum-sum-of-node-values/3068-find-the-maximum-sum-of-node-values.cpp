// TC->O(N*2)
// SC->O(20001) = O(1)
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        long long dp[20001][2]={0};
        dp[n][0]=0, dp[n][1]=INT_MIN;
        for(int i=n-1; i>=0; i--){
            long long x=nums[i];
            for ( int c=0; c<=1; c++)
                dp[i][c]=max(x+dp[i+1][c], (x^k)+dp[i+1][!c]);
        }

        return dp[0][0];
    }
};