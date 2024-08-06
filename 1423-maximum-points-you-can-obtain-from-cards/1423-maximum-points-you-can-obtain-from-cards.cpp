// TC->O(2*k)
// SC->O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftS = 0;
        for(int i=0;i<k;i++) leftS+= cardPoints[i];

        int rightS = 0;
        int j = n-1,maxi = leftS;
        for(int i =k-1;i>=0;i--){
            leftS-=cardPoints[i];
            rightS+=cardPoints[j--];
            maxi = max(leftS+rightS,maxi);
            
        }
        return maxi;
    }
};