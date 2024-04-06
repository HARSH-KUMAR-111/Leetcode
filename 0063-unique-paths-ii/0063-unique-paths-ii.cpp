// Memoization
// TC-> O(m*n)
// SC-> O(m*n)
class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>> &mat,vector<vector<int>> &dp){
        if(i>m || j>n) return 0;
        if(mat[i][j]==1) return 0;
        if(i==m && j==n) return 1;
        

        if(dp[i][j] !=-1) return dp[i][j];

        int right = func(i,j+1,m,n,mat,dp);
        int down = func(i+1,j,m,n,mat,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size()-1;
        int n= obstacleGrid[0].size()-1;

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return func(0,0,m,n,obstacleGrid,dp);
    }
};