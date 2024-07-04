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

//TC->O(N)
//SC->O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tmp=dummyNode;

        head=head->next;
        int sum=0;
        while(head){
            if(head->val != 0 ){
                sum+=head->val;
            }
            else{
                ListNode* node=new ListNode(sum);
                tmp->next=node;
                tmp=tmp->next;
                sum=0;
            }
            head=head->next;
        } 
        return dummyNode->next;
    }
};