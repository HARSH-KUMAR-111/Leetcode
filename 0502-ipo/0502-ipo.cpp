//TC->O(nlogn)
//SC->O(2*n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vc; // capital profits

        for(int i=0;i<capital.size();i++){
            vc.push_back({capital[i],profits[i]});
        }
        sort(vc.begin(),vc.end());
        priority_queue<int> pq; 
        int ans=w,i=0;
        while(k--){

            while(i<capital.size() && vc[i].first<=ans){
                pq.push(vc[i++].second);
            }

            if(!pq.empty()){
                ans+=pq.top();
                pq.pop();
            }
        }
        
        return ans;
    }
};