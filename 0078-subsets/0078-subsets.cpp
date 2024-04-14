// Bit Manipulation
// TC -> O(N x 2^N)
// SC -> O(N x 2^N)  
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int len=1<<nums.size();
       vector<vector<int>> ans;
       for(int i=0;i<len;i++){
            vector<int> ls;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    ls.push_back(nums[j]);
                }
            }
            ans.push_back(ls);
       }
       return ans;
    }
};
//  n =3
//  nums={1,2,3}
//   i     ind  
//  000 -- 0
//  001 -- 1
//  010 -- 2
//  011 -- 3
//  100 -- 4
//  101 -- 5
//  110 -- 6
//  111 -- 7