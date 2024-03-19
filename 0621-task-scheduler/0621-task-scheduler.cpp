class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26];

        for(char it: tasks){
            freq[it-'A']++;
        }

        sort(freq,freq+26);
        int interval=freq[25]-1;
        int idle=interval*n;

        for(int i=24;i>=0;i--){
            idle-=min(interval,freq[i]);
        }

        if(idle>0) return tasks.size()+idle;

        return tasks.size();
    }
};