class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0,j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int score=0,maxScore=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                score++;
            }
            else{
                power+=tokens[j--];
                score--;
            }
            if(score<0) break;
            maxScore=max(maxScore,score);
        }
        return maxScore;
    }
};