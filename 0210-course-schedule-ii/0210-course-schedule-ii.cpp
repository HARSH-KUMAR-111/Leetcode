//TC->O(V+E)
//SC->O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> res;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(numCourses != res.size()) return {};

        return res;
    }
};