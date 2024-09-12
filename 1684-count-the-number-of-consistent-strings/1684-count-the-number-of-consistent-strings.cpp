// TC->O(n)
// SC->O(26)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mpp;
        
        for(char it: allowed) mpp[it]=1;
        int len = allowed.size();
        
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int flag =0;
            for(char it : words[i]){
                if(mpp.find(it) == mpp.end()){
                    flag =1;
                    break;
                }
                
            }
            if(flag == 0) cnt++;
        }
        return cnt;
    }
};