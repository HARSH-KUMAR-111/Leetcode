/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto elem=q.front();
            q.pop();

            TreeNode* node=elem.first;
            int x=elem.second.first,y=elem.second.second;

            mpp[x][y].insert(node->val);

            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }


        for(auto it: mpp){
            vector<int> col;
            for(auto itt: it.second){
                for (int val : itt.second) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};