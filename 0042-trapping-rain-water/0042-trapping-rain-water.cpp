class Solution {
public:
    /*
       Optimal Solution
       TC->O(N)
       SC->O(1)
    */
    int trap(vector<int>& height) {
        //better Solution
        int n=height.size();
        int waterTrapped=0;
        int left=0,right=n-1;
        int leftmax=0,rightmax=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftmax){
                    leftmax=height[left];
                }
                else{
                    waterTrapped+=(leftmax-height[left]);
                }
                left++;
            }
            else{
                if(height[right]>=rightmax){
                    rightmax=height[right];
                }
                else{
                    waterTrapped+=(rightmax-height[right]);
                }
                right--;
            }
        }
        return waterTrapped;
    }
};