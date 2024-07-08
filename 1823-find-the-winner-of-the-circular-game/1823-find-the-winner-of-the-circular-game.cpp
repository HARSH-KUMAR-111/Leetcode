// TC->O(N+N)
// SC->O(N)
class Solution {
public:
    int findTheWinner(int n, int k) {
        int pos=0;
        vector<int> friends(n);

        for(int i=0;i<n;i++) friends[i] = i+1;
        cout<<friends[0];

        while(friends.size()>1){
            pos+=(k-1);

            pos%=friends.size();
            friends.erase(friends.begin()+pos);
        }
        return friends[0];

    }
};