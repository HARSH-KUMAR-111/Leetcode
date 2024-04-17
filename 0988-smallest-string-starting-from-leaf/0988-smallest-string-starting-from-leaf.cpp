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
 // TC-> O(nlogn)
 // SC->O(n)
class Solution {
public:
    void func(TreeNode* root,vector<string> &ans,string str){
        if(root==NULL) {
            return;
        }
        
        string tmp = char('a' + root->val)+str;

        if(root->left==NULL && root->right==NULL){
            ans.push_back(tmp);
        }
        func(root->left,ans,tmp);
        func(root->right,ans,tmp);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string s="";

        func(root,ans,s);

        sort(ans.begin(),ans.end());

        return ans[0];
    }
};