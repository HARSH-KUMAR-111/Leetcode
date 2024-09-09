/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // TC->O(m*n)
 // SC->O(m*n)
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));

        int l=0,r=n-1,u=0,d=m-1;
        ListNode* tmp = head;
        while(tmp){
            for(int i=l;i<=r && tmp;i++){
                mat[u][i] = tmp->val;
                tmp=tmp->next;
            }
            u++;
            for(int i=u;i<=d && tmp;i++){
                mat[i][r] = tmp->val;
                tmp=tmp->next;
            }
            r--;

            for(int i=r; i>=l && tmp;i--){
                mat[d][i] = tmp->val;
                tmp=tmp->next;
            }
            d--;
            for(int i=d;i>=u && tmp;i--){
                mat[i][l] = tmp->val;
                tmp=tmp->next;
            }
            l++;
        }
        return mat;
    }
};