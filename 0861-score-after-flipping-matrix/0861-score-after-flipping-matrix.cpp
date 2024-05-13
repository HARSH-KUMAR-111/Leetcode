// Bit Manipulation
// TC->O(N^2)
// SC->O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0] == 0){
                for(int j=0;j<m;j++){
                    grid[i][j]^=1;
                }
            }
        }

        for(int j=1;j<m;j++){
            int colcnt=0;

            for(int i=0;i<n;i++){
                if(grid[i][j] == 1){
                    colcnt++;
                }
            }
            if(colcnt < n-colcnt){
                for(int i=0;i<n;i++){
                    grid[i][j]^=1;
                }
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=grid[i][j]*(1<<(m-1-j));
            }
        }
        return ans;
    }
};