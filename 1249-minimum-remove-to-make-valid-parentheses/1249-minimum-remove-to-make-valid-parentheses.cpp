// TC-> O(N)
// SC-> O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(cnt==0 && s[i]==')'){
                s[i]='.';
            }
            else if(s[i]==')'){
                cnt--;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(' && cnt>0){
                s[i]='.';
                cnt--;
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.')
                continue;
            ans+=s[i];
        }
        return ans;
    }
};