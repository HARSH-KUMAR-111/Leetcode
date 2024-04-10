// Memoization
// TC-> O(n^2)
// SC-> O(n^2)
class Solution {
public:
    int func(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(i==n) return arr[n][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down= arr[i][j] + func(i+1,j,n,arr,dp);
        int diagonal= arr[i][j] + func(i+1,j+1,n,arr,dp);
        return dp[i][j] = min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();

        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,0,n-1,triangle,dp);
    }
};