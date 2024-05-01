// TC-> O(n*m) where m =ans.size()
// SC-> O(1)
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans="11";
        
        for(int i=2;i<n;i++){
            string str="";
            int cnt=1;

            for(int j=0;j<ans.size()-1;j++){
                if(ans[j]==ans[j+1]){
                    cnt++;
                }
                else{
                    str+=to_string(cnt);
                    str+=ans[j];
                    cnt=1;
                }
            }
            str+=to_string(cnt)+ans[ans.size()-1];
            ans=str;
        }
        return ans;
    }
};