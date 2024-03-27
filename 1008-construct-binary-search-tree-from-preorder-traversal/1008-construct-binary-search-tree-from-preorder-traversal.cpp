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


 // TC-> O(N)
 // SC-> O(1)

class Solution {
public:
    TreeNode* buildBST(vector<int>& A,int &i,int bound){
        if(i==A.size() || A[i]>bound) return NULL;

        TreeNode* node=new TreeNode(A[i++]);
        node->left = buildBST(A,i,node->val);
        node->right = buildBST(A,i,bound);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildBST(preorder,i,INT_MAX);
    }
};