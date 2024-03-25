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
    bool BST(TreeNode* root,long minVal,long maxVal){
        if(!root) return true;
        
        if(root->val >=maxVal || root->val <=minVal) return false;
        int leftSubTree= BST(root->left,minVal,root->val);
        int rightSubTree= BST(root->right,root->val,maxVal);

        return leftSubTree && rightSubTree;
    }
    bool isValidBST(TreeNode* root) {
        
        return BST(root,LONG_MIN,LONG_MAX);
    }
};