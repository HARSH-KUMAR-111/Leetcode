//Sliding Window
// TC-> O(N)
// SC-> O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int cnt=0,i=0,j=0;
        int n=nums.size();


        int maxElem=*max_element(nums.begin(),nums.end());

        while(j<n){
            if(nums[j]==maxElem)
                cnt++;
            while(cnt>=k){
                if(nums[i]==maxElem)
                    cnt--;
                i++;
            }
            ans+=i;
            j++;
        }
        return ans;
    }
};