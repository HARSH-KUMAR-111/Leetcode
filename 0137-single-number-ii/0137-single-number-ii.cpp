// Bit Manipulation
// TC-> O(N*32)
// SC -> O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;

        for(int bitInd=0;bitInd<=31;bitInd++){
            int cnt=0;
            for(int i=0;i<nums.size();i++){

                if(nums[i]&(1<<bitInd)) cnt++;
            }
            if(cnt%3==1) ans|=(1<<bitInd);
        }
        return ans;
    }
};