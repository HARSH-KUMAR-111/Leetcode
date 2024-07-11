class Solution {
public:
    int func(int ind, int amt, vector<int> &coins, vector<vector<int>> &dp) {
    if (ind == -1) {
        if (amt == 0) return 0;
        return INT_MAX;
    }
    if (amt==0) return 0;

    if (dp[ind][amt] != -1) return dp[ind][amt];
    int pick = INT_MAX;

    if (coins[ind]<=amt) {
        int x= func(ind,amt-coins[ind],coins,dp);
        if(x!=INT_MAX) pick =1+x;
    }
    int notpick = func(ind-1,amt,coins,dp);

    return dp[ind][amt] = min(pick, notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount ==0 ) return 0;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
       
        int ans=func(n-1,amount,coins,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};