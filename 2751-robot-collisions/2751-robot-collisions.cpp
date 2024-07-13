// TC->O(nlogn+ 3*n)
// SC->O(2*2*n) = O(n)

class Solution {
public:
    int IndexVal(vector<int> &pos,int val){
        for(int i=0;i<pos.size();i++){
            if(val==pos[i]) return i;
        }
        return -1;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        stack<pair<pair<int,int>,pair<char,int>>> st;
        vector<pair<pair<int,int>,pair<char,int>>> vc;

        for(int i=0;i<n;i++){
            vc.push_back({{positions[i],i},{directions[i],healths[i]}});
        }
        sort(vc.begin(),vc.end());
        // for(auto it:vc){
        //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }

        for(int i=0;i<n;i++){
            int x =vc[i].second.first;
            int y = vc[i].second.second;
            while( x=='L' && !st.empty() && st.top().second.first =='R' && y >  st.top().second.second)
            {
                y-=1;
                st.pop();
            }
            if(x=='L' && !st.empty() && st.top().second.first =='R' && y <  st.top().second.second){
                st.top().second.second -= 1;
                continue;
            }
            else if (x=='L' && !st.empty() && st.top().second.first =='R' && y ==  st.top().second.second){
                st.pop();
                continue;
            }
            st.push({{vc[i].first.first,vc[i].first.second},{vc[i].second.first, y}});
        }

        vector<int> ans(n,-1);
        int size = st.size();
        while(!st.empty()){
            int idx = st.top().first.second;
            ans[idx]=st.top().second.second;
            st.pop();
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i] !=-1) res.push_back(ans[i]);
        }
        return res;
    }
};