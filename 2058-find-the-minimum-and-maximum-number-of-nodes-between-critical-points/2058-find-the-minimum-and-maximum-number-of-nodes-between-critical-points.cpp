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

 // TC->O(N)
 // SC->O(N)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;

        vector<int> MinMax;
        ListNode* tmp=head;
        ListNode* prev=NULL;
        int pos=1;
        while(tmp && tmp->next){
            if(prev && tmp->next){
                if((prev->val<tmp->val && tmp->next->val<tmp->val) || (prev->val>tmp->val && tmp->next->val>tmp->val)){
                    MinMax.push_back(pos);
                }
            }
            pos++;
            prev=tmp;
            tmp=tmp->next;
        }
        // for(int i=1;i<arr.size()-1;i++){
        //     if((arr[i]<arr[i-1] && arr[i]<arr[i+1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1])){
        //         MinMax.push_back(i+1);
        //     }
        // }


        int n=MinMax.size();
        if(n<2) return {-1,-1};


        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            mini=min(mini,MinMax[i]-MinMax[i-1]);
        }
        return {mini,MinMax[n-1]-MinMax[0]};

    }
};