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
class Solution {
public:
    ListNode* reverseLL(ListNode* newhead){
        ListNode* prev=nullptr;
        ListNode* temp=newhead;
        
        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseLL(slow->next);

        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseLL(newHead);
                return 0;
            }
            first=first->next;
            second=second->next;

        }
        reverseLL(newHead);
        return true;
        return 1;
    }
};