class Solution {
public:
    int M=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        //Monotonic Stack
        int n=arr.size();
        vector<int> left(n,0),right(n,0);
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() && st.top().first>arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            left[i]=cnt;
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st.empty() && st.top().first>=arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            right[i]=cnt;
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=(ans+(long long)left[i]*right[i]*arr[i])%M;
        }
        return ans;
    }
};