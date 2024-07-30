// TC->O(N)
// SC->O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int cntB = 0; 
        int del = 0; 
        
        for (int i=0;i<s.length();i++) {
            if (s[i] == 'b') {
                cntB++; 
            }
            else{
                del = min(del+1,cntB);
            }
        }
        
        return del;
    }
};