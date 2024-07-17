// TC->O(N)
// SC->O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump =0;
        int l=0,r=0; //ranges
        int n= nums.size();
        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, i+nums[i]);
            }
            l=r+1; r= farthest;
            jump+=1;
        }
        return jump;  
    }
};