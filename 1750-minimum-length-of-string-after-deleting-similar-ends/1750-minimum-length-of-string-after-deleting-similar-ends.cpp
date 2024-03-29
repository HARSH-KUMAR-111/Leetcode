class Solution {
public:
    int minimumLength(string s) {
        int left=0,right=s.size()-1;

        while(left<right && s[left]==s[right]){
            char c=s[left];
            while(left<right+1 && s[left]==c) left++;
            while(left-1<right && s[right]==c) right--;
        }

        return right-left+1;
    }
};