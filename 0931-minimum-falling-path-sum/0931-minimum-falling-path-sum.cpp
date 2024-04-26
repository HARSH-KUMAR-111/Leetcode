// tabulation
// TC-> O(N^2)
// SC-.O(N^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[0][j]=mat[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = mat[i][j]+dp[i-1][j];

                int diaLeft=INT_MAX,diaRight=INT_MAX;

                if(j-1>=0) diaLeft=mat[i][j]+dp[i-1][j-1];

                if(j+1<n) diaRight=mat[i][j]+dp[i-1][j+1];

                dp[i][j]=min(up,min(diaLeft,diaRight));
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};