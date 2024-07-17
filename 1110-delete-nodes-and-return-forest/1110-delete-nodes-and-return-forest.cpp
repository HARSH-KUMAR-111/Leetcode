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

 // TC->O(N)
 // SC->O(N)
class Solution {
public:
    TreeNode* dfs(TreeNode* root, vector<TreeNode*> &ans,unordered_map<int,int> &mp){
        if(!root) return root;

        root->left =dfs(root->left,ans,mp);
        root->right =dfs(root->right,ans,mp);

        if(mp.find(root->val) !=mp.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
        vector<TreeNode*> ans;
        unordered_map<int,int> mp;

        for(auto it:to_del){
            mp[it]++;
        }
        dfs(root,ans,mp);
        if(mp.find(root->val) == mp.end()){
            ans.push_back(root);
        }
        return ans;
    }
};