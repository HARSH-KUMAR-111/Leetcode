class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int> &vis){
        vis[i]=1;
        for (int j=0; j<adj.size(); j++) {
            if (adj[i][j] && !vis[j] ) {
                dfs(j,adj,vis);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};