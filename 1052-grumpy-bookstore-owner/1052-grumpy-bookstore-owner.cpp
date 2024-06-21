//TC->O(N+N)
//SC->O(1)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //sliding window of size-> minutes

        int n=customers.size();
        int maxi=0,sum=0;

        int i=0,j=0;
        while(j<n){
            if(grumpy[j]==1){
                sum+=customers[j];
                //cout<<sum<<" ";
            }
            if(j-i+1==minutes){
                maxi=max(sum,maxi);
                
                if(grumpy[i]==1) sum-=customers[i];
                i++;
            }
            j++;
        }
        cout<<maxi<<" ";
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }
        return ans+maxi;
    }
};