// TC->O(N)
// SC->O(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        stack<pair<int,int>> st;  // temp, ind
        vector<int> ans(n);
        for(int i=0;i<temp.size();i++){
            while(!st.empty() && st.top().first<temp[i]){
                int ind=st.top().second;
                ans[ind]=(i-ind);
                st.pop();
            }
            st.push({temp[i],i});
        }
        while(!st.empty()) st.pop();
        return ans;
    }
};
