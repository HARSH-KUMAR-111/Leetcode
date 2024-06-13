// TC->O(N) where N is no. of rows
// SC->O(N)
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();

        if(n<=numRows) return s;
        vector<string> vc(numRows);
        int flag=1;
        int j=0;
        if(numRows == 1) return s;
        for(int i=0;i<n;i++){
            vc[j]+=s[i];
            if(flag) j++;
            else j--;
            
            if(j==numRows){
                flag=0;
                j=numRows-2;
            }
            if(j<0){ 
                j=1;
                flag=1;
            }
        }
        string ans="";
        for(auto it:vc){
            ans+=it;
        }
        return ans;
    }
};