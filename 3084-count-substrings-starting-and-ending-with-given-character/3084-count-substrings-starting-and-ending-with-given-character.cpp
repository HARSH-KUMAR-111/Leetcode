#define ll long long
class Solution {
public:
    long long countSubstrings(string s, char c) {
        ll ans=0;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){ 
           if (s[i] == c) {
               cnt++;
           }
        }
        ans=(ll)cnt*(cnt+1)/2;
        return ans;
    }
};