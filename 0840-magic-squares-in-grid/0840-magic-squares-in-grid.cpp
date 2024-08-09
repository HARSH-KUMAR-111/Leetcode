// TC->O((N-3)*(M-3)*(9+9+9)) = O(N*M)
// SC->O(16)
class Solution {
public:
    bool isMagicGrid(int len1,int len2,vector<vector<int>>& grid){
        vector<int> vis(16,0);
        for (int i=len1;i<len1+3;i++) {
            for (int j=len2;j<len2+3;j++) {
                if (grid[i][j]<1 || grid[i][j]>9 || vis[grid[i][j]]) return false;
                vis[grid[i][j]] = 1;
            }
        }

        // diagonal sum
        int diagSum1 = grid[len1][len2]+grid[len1+1][len2+1]+grid[len1+2][len2+2];
        int diagSum2 = grid[len1][2+len2]+grid[len1+1][1+len2]+grid[len1+2][len2];

        if(diagSum1 != diagSum2) return false;
        
        // Row Sum
        for(int i=len1;i<3+len1;i++){
            int rowSum=0;
            for(int j=len2;j<3+len2;j++){
                rowSum += grid[i][j];
            }
            if(rowSum != diagSum1) return false;
        }
        
        // Column Sum
        for(int j=len2;j<3+len2;j++){
            int colSum=0;
            for(int i=len1;i<3+len1;i++){
                colSum += grid[i][j];
            }
            if(colSum != diagSum1) return false;
        }
        //cout<<diagSum1<<" "<<diagSum2<<endl;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n<3 && m<3) return 0;

        int cnt=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                
                if(isMagicGrid(i,j,grid)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};