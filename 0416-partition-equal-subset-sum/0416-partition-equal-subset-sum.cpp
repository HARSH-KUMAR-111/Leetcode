// Memoization
// TC-> O(n*sum)
// SC-> O(n*sum)
class Solution {
public:
    bool func(int ind,int sum,vector<int> &arr,vector<vector<int>> &dp){
        if(sum==0){
            return true;
        }
        if(ind==0) {
            return arr[0]==sum;
        }
        if(dp[ind][sum] !=-1) return dp[ind][sum];

        bool pick=false;
        if(sum>=arr[ind]) pick=func(ind-1,sum-arr[ind],arr,dp);

        bool notpick= func(ind-1,sum,arr,dp);

        return dp[ind][sum] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        // int sum=0;
        // for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2 !=0) return false;
        int target=sum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return func(n-1,target,nums,dp);

    }
};