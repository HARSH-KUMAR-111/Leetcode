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
 //SC->O(N-1)
class Solution {
public:
    int gcd(int n1,int n2){
        if(n2==0) return n1;

        return gcd(n2,n1%n2);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode* num1=head;
        ListNode* num2=head->next;

        while(num2){
            ListNode* newNode = new ListNode(gcd(num1->val,num2->val));
            num1->next = newNode;
            newNode->next = num2;
            num1=num2;
            num2=num2->next;
        }
        return head;
    }
};