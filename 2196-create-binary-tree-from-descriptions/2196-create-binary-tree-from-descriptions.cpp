//TC->O(N)
//SC->O(N)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n = desc.size();
        unordered_map<int,TreeNode*> mpp1;
        unordered_map<int,int> mpp2; 

        for(int i=0;i<n;i++){
            int x= desc[i][0];
            int y= desc[i][1];
            if(mpp1.find(x) == mpp1.end()){
                mpp1[x] = new TreeNode(x);
            }
            if(mpp1.find(y) == mpp1.end()){
                mpp1[y] = new TreeNode(y);
            }
            mpp2[y] = 1;
        }

        TreeNode* head = NULL;
        for(int i=0;i<n;i++){
            int x= desc[i][0];
            int y= desc[i][1];
            
            TreeNode* parent=mpp1[x];
            TreeNode* child =mpp1[y];
            if(desc[i][2]){
                parent->left = child;
            }
            else{
                parent->right =child;
            }
            if(mpp2.find(x) == mpp2.end()) head= mpp1[x];
        }
        return head;
    }
};