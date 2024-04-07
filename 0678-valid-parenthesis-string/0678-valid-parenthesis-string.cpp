//Memoization
//TC -> O(N^2)
//SC -> O(N^2)+O(N)
class Solution {
public:
    int func(int ind,string &s,int cnt,vector<vector<int>> &dp){
        if(ind==s.size()) return cnt==0;
        if(cnt<0) return 0;
        if (dp[ind][cnt] != -1) return dp[ind][cnt];

        int ans = 0;

        if (s[ind]=='(') {
            ans=func(ind + 1, s, cnt + 1, dp);
        } 
        else if(s[ind]=='*') {
            ans=func(ind + 1, s, cnt + 1, dp) || func(ind + 1, s, cnt, dp) || func(ind + 1, s, cnt - 1, dp);
        } 
        else if(s[ind] == ')') {
            ans=func(ind + 1, s, cnt - 1, dp);
        }

        return dp[ind][cnt]=ans;
    }
    bool checkValidString(string s) {
        int cnt=0;
        vector<vector<int>> dp(101,vector<int>(100,-1));

        return func(0,s,cnt,dp) == 1; 

    }
};