// TC->O(n)
// SC->O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(),chalk.end(),0LL);

        long long x = k%sum;

        while(x>= chalk[i]){
            x-=chalk[i++];
        }
        return i;
    }
};