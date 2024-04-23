class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int time=0,cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({time,{i,j}});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        vector<int> dRow={-1,0,1,0}; //direction of rows
        vector<int> dCol={0,-1,0,1};
        int newCnt=0;
        while(!q.empty()){
            int tm=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            
            time=max(tm,time);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row+dRow[i];
                int ncol = col+dCol[i];

                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && vis[nrow][ncol] !=2 && grid[nrow][ncol]==1){
                    q.push({tm+1,{nrow,ncol}});
                    vis[nrow][ncol]=2;
                    newCnt++;
                }
            }
        }

        if(newCnt!= cnt){
            return -1;
        }
        return time;

    }
};