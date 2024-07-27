// Memoization
// TC->O(N*2*3)
// SC->O(N*2*3)
class Solution {
public:
    int func(int ind,int n,vector<int> &pro,int buy,vector<vector<vector<int>>> &dp,int cap){
        if(ind == n){
            return 0;
        }
        if(cap == 0) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-pro[ind]+func(ind+1,n,pro,0,dp,cap),func(ind+1,n,pro,1,dp,cap));
        }
        else{
            profit = max(pro[ind]+func(ind+1,n,pro,1,dp,cap-1),func(ind+1,n,pro,0,dp,cap));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        return func(0,n,prices,1,dp,2);
    }
};