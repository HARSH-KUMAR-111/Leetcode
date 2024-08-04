class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        if(n == k) return accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        vector<int> pref(n,0);
        pref[0] = cardPoints[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+cardPoints[i];
        }

        vector<int> suff(n,0);
        suff[n-1] = cardPoints[n-1]; 
        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1]+cardPoints[i];
        }

        int j =k-2,i= n-1;
        int maxSum = max(suff[n-k],pref[k-1]);
        while(j>=0){
            maxSum = max(maxSum,pref[j--]+suff[i--]);
        }
        return maxSum;
    }
};