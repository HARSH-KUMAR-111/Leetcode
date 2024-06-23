// Sliding window+ monotonic queue concept
// TC->O(N)
// SC->O(N)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int> mini,maxi;

        int i=0,j=0;
        int maxLen=-1;
        while(j<n){

            while(!mini.empty() && mini.back()>nums[j]){
                mini.pop_back();
            }
            while(!maxi.empty() && maxi.back()<nums[j]){
                maxi.pop_back();
            }
            mini.push_back(nums[j]);
            maxi.push_back(nums[j]);

            while(maxi.front()-mini.front()>limit){
                if(maxi.front()==nums[i]) maxi.pop_front();
                if(mini.front()==nums[i]) mini.pop_front();

                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};