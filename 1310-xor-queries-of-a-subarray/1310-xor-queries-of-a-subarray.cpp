// TC->O(n+m)
// SC->O(n+m)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        vector<int> pref(n);
        
        pref[0] = arr[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]^arr[i];
        }
        
        for(auto it: queries){
            int x = it[0];
            int y = it[1];
            
            if(x == 0) {
                ans.push_back(pref[y]);
            }
            else{
                ans.push_back(pref[y]^pref[x-1]);
            }
        }
        return ans;
    }
};