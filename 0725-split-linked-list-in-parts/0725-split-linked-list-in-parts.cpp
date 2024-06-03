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

// TC->O(N+N)
// SC->O(1)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        // if(head==NULL && k==1){ 
        //     ans.push_back({});
        //     return ans;
        // }
        
        ListNode* tmp=head;
        int len=0;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        
        tmp=head;
        // if(len==1 && k==1){
        //     ans.push_back(head);
        //     return ans;
        // }
        
        if(len<=k){
            while(tmp){
                ListNode* front=tmp->next;
                tmp->next=NULL;
                ans.push_back(tmp);
                tmp=front;
            }
            int x=k-len;
            while(x--){
                ans.push_back({});
            }
            return ans;
        }

        tmp=head;
        while(len>1){
            int val=ceil(static_cast<double>(len)/k);
            cout<<val<<" ";
            if(tmp!=NULL) ans.push_back(tmp);
            while(val>1){
                if(tmp) tmp=tmp->next;
                val--;
            }
            if(tmp==NULL) break;
            ListNode* front=tmp->next;
            tmp->next=NULL;
            tmp=front;
            len=len-val;
        }

        // int grp=len/k;
        // int left=len%k;
        // tmp=head;

        // while(left--){
        //     int newgrp=grp+1;
        //     int len=0;
        //     while(tmp){
        //         ListNode* front = tmp->next;
        //         if(newgrp==len){

        //         }
        //         len++;
        //     }
        // }
        return ans;
    }
};