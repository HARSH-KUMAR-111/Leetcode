#define ll long long
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll ans=nums.size();
        int j=0;

        for(ll i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) {
                ans+=(i-j);
            }
            else{
                j=i;
            }
        }
        return ans; 
    }
};