// TC->O(N) where N is s length
// SC->O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int cnt=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        cnt+=(t.length()-j);

        return cnt;
    }
};