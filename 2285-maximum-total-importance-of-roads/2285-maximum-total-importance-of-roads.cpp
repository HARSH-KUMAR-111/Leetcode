#define ll long long 
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        priority_queue<int> pq;
        vector<int> vc(n);

        for(int i=0;i<roads.size();i++){
            vc[roads[i][0]]++;
            vc[roads[i][1]]++;
        }
        for(int i=0;i<n;i++){
            pq.push(vc[i]);
        }
        //cout<<pq.top().first<<pq.top().second;

        ll res=0;
        for(int i=0;i<n;i++){
            res+=(ll)(n-i)*pq.top(); //5
            pq.pop();
        }

        return res;
    }
};