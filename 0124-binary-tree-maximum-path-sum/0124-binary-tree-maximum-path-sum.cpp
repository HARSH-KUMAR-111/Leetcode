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
private:
    int MaxSum(TreeNode* node,int &maxi){
        if(node==nullptr) return 0;
        
        //leftside ka maximum sum include krenge
        int leftMax=max(0,MaxSum(node->left,maxi));
        
        //max(0,__) se compare krne ka reason hai ki agr negative values aagyi to 0 le lega unhe
        
        //rightside ka maximum sum include krenge
        int rightMax=max(0,MaxSum(node->right,maxi));
        maxi=max(maxi,node->val+leftMax+rightMax);
        
        return node->val+max(leftMax,rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        
        int maxi=INT_MIN;
        MaxSum(root,maxi);
        
        return maxi;
    }
};