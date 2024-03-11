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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> NodeQ;

        NodeQ.push(root);
        bool flag=true;

        while(!NodeQ.empty()){
            int size=NodeQ.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node =NodeQ.front();
                NodeQ.pop();
                int index=( flag ? i:(size-i-1));
                row[index]=node->val;
                if(node->left) NodeQ.push(node->left);
                if(node->right) NodeQ.push(node->right);
            }
            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};