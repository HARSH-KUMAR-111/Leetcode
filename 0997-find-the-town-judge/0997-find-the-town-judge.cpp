class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> judge(n+1,{0,0});
        for(int i=0;i<trust.size();i++){
            judge[trust[i][0]].first+=1;
            judge[trust[i][1]].second+=1;
        }
        for(int i=1;i<=n;i++){
            if(judge[i].first==0 && judge[i].second==n-1){
                return i;
            }
        }
        return -1;
    }
};