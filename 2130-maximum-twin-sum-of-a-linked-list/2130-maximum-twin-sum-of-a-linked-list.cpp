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
    int pairSum(ListNode* head) {
        vector<int> vc;
        ListNode* temp=head;
        while(temp){
            vc.push_back(temp->val);
            temp=temp->next;
        }
        int n=vc.size();
        int maxSum=0;
        for(int i=0;i<n;i++){
            int sum=vc[i]+vc[n-i-1];
            maxSum=max(maxSum,sum);
        }
        return maxSum;

    }
};