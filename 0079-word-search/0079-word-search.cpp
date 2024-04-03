// Backtracking
// TC->O(m*n*4^L) where 4^L is 4 direction and L is length of word
// SC-> O(m*n)
class Solution {
private:
    bool searchWord(int i,int j,int ind,string word, vector<vector<bool>> &visited,vector<vector<char>>& board){
        if(ind==word.size()){
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] || word[ind] != board[i][j]){
            return false;
        }
        visited[i][j]=true;
        if(searchWord(i+1,j,ind+1,word,visited,board) ||
        searchWord(i,j+1,ind+1,word,visited,board) ||
        searchWord(i-1,j,ind+1,word,visited,board) ||
        searchWord(i,j-1,ind+1,word,visited,board)){
            return true;
        }
        visited[i][j]=false;
        return false;
    }
public:

    bool exist(vector<vector<char>>& board, string word) {
        
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col));

        if(word.size()>row*col){
            return false;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0]==board[i][j] && searchWord(i,j,0,word,visited,board)){
                    return true;
                }
            }
        }
        return false;
    }
};