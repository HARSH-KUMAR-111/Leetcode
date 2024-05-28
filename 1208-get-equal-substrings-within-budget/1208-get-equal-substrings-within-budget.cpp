class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       
        int i=0,j=0;
        int mx=maxCost,maxLen=0, diff=0;
        while(j<s.size()){
            diff=abs(s[j]-t[j]);
            mx-=diff;
            //cout<<diff<<" ";
            while(mx<0 && i<=j){
                //maxLen=max(maxLen,j-i+1);
                mx+=abs(s[i]-t[i]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }

        return maxLen;
    }
};