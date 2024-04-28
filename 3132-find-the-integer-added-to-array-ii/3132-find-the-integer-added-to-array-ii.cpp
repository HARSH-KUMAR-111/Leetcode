// TC-> O(nlog n)+O(N^2)
// SC-> O(1)
class Solution {
public:
    bool checkEle(vector<int>& nums1, vector<int>& nums2,int diff){
        
        int notake=0,i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]+diff==nums2[j]) j++;
            else notake++; 
            i++;
        }
        if(notake>2) return false;
        return true;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end()); 
        sort(nums2.begin(),nums2.end());      
        int ans=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            int diff=nums2[0]-nums1[i];

            //check function to check if the element to be removed or not
            if(checkEle(nums1,nums2,diff)){
                ans=min(ans,diff);
            }
        }
        return ans;
    }
};