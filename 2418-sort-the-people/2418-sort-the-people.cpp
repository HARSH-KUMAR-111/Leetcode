// TC->O(2*N)
// SC->O(2*N)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> ds;

        for(int i=0;i<names.size();i++){
            ds.push_back({names[i],heights[i]});
        }   

        vector<string> ans;

        //compartor sort with anonymous function
        sort(ds.begin(),ds.end(),[](pair<string,int> &val1,pair<string,int> &val2){
            return val1.second>val2.second;
        });

        for(auto it: ds){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i=0;i<ds.size();i++){
            ans.push_back(ds[i].first);
        }
        return ans;
    }
};