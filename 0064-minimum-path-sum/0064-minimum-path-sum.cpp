// Memoization
// TC-> O(m*n)
// SC-> O(m*n)+O(N)
class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==m && j==n){
            return grid[i][j];
        }
        if(i>m || j>n) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int left=grid[i][j]+func(i,j+1,m,n,grid,dp);
        int down=grid[i][j]+func(i+1,j,m,n,grid,dp);
        
        return dp[i][j]=min(left,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,m-1,n-1,grid,dp);
    }
};