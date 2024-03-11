class Solution {
public:
    string customSortString(string order, string s) {
        //ordered map to store the left elem in lexi
        unordered_map<char,int> mpp;
        string ans="";
        for(char &it: s){
            mpp[it]++;
        }
        for(int i=0;i<order.size();i++){
            int x=order[i];
            if(mpp.find(x)!=mpp.end()){
                int cnt=mpp[x];
                string s(cnt,x); 
                ans+=s;
                mpp.erase(x);
            }
        }
        for(auto &it:mpp){
            string s(it.second,it.first);
            ans+=s;
        }
        
        return ans;
    }
};