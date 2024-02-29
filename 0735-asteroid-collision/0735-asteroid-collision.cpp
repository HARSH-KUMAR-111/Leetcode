class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
    
        int n=asteroids.size();
        for(auto it: asteroids){
            
            while(!st.empty() && it<0 && st.top()>0){
                int sum=it+st.top();
                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    it=0;
                }
                else{
                    st.pop();
                    it=0;
                }
            }
            if(it!=0){
                st.push(it);
            }
        }
        int s=st.size();
        vector<int> ans(s);
        int i=s-1;

        while(!st.empty()){
            ans[i]=st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};