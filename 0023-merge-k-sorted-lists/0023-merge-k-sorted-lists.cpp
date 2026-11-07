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
    ListNode* merge2Lists(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<=l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;

            }
            tail=tail->next;
        }
        if(l1!=NULL)
        tail->next=l1;
        else
        tail->next=l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* result = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            result = merge2Lists(result, lists[i]);
        }
        return result;
        
    }
};