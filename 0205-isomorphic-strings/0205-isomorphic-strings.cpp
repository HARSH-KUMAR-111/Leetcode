// TC->O(N)
// SC->O(N+M)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size(),n2=t.size();

        if(n1!=n2) return false;
        unordered_map<int,int> mpp1,mpp2;

        for(int i=0;i<n1;i++){

            if(mpp1[s[i]]==0 && mpp2[t[i]]==0){
                mpp1[s[i]]=t[i];
                mpp2[t[i]]=s[i];
            }
            if(mpp1[s[i]] != t[i] && mpp2[t[i]] != s[i]){
                return false;
            }
        }
        return true;

    }
};