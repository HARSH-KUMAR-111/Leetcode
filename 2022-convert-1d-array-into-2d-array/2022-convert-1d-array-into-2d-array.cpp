// TC->O(len(original))
// SC->O(m*n)
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        int row=0,col=0;
        if(m*n != original.size()) return {};
        for(int i=0;i<original.size();i++){
            if(row>=m) break;
            mat[row][col] = original[i];
            if(col<n-1){
                col++;
            }
            else{
                col =0;
                row++;
            } 
            
        }
        return mat;
    }
};