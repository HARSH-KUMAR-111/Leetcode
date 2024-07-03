// TC->O(nlogn)
// SC->O(1)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());

        int mini=INT_MAX;
        //4 possibilities
        // 1 elem & last 4th elem.
        mini=min(mini,nums[n-4]-nums[0]);
        // 4th from starting and last elem.
        mini=min(mini,nums[n-1]-nums[3]);
        // 2 from start & 2nd last
        mini=min(mini,nums[n-2]-nums[2]);
        // 
        mini=min(mini,nums[n-3]-nums[1]);

        return mini;
    }
};