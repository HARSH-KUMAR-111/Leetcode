// TC->O(NlogN)
// SC->O(N^2)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size(); 
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> tmp=intervals[0];
        for(int i=1;i<n;i++){
            if(tmp[1]>=intervals[i][0]){
                tmp[1]=max(tmp[1],intervals[i][1]);
            }
            else{
                ans.push_back(tmp);
                tmp=intervals[i];
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};