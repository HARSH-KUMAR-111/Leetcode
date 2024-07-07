// Recursion
// TC->O(2^N)
// SC->O(N)
class Solution {
public:
    void func(int ind,int n,vector<string> &ans,string str){
        if(ind==n){
            for(int i=1;i<str.length();i++){
                if(str[i-1] =='0' && str[i] == '0')
                  return;
            }
            ans.push_back(str);
            return;
        }
        // if(str.length()>=2){
        //     for(int i=1;i<str.length();i++){
        //         if(str[i-1] =='0' && str[i] == '0')
        //           return;
        //     }
        // }
        func(ind+1,n,ans,str+"0");
        func(ind+1,n,ans,str+"1");
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        func(0,n,ans,"");

        return ans;
    }
};