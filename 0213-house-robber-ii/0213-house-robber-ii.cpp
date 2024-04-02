// TC->O(N)
// SC->O(2N)
class Solution {
public:
    int func(vector<int>& nums){
        int n=nums.size();
        
        int prev=nums[0],prev2=0;

        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick =0 + prev;
            int curri=max(pick,notpick);
            prev2=prev;
            prev=curri;
        }
        return prev;

    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        vector<int> tmp1,tmp2;
        for(int i=0;i<n;i++){
            if(i!=0) tmp1.push_back(nums[i]);
            if(i!=n-1) tmp2.push_back(nums[i]);
        }
        return max(func(tmp1),func(tmp2));
    }
};