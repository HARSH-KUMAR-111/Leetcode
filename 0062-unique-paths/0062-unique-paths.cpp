// Memoization
// TC->O(m*n)
// SC->O(m*n)+O((m-1)+(n-1))
class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m && j==n) return 1;
        if(i>m || j>n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=func(i,j+1,m,n,dp);
        int down=func(i+1,j,m,n,dp);

        return dp[i][j]=right+down; 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return func(0,0,m-1,n-1,dp);
    }
};