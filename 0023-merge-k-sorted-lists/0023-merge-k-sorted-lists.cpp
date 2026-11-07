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
        if(lists.empty()) return NULL;
        int k =lists.size();
        while(k>1){
            int i=0,j=0;
            while(i<k){
                if(i+1<k){
                    lists[j]=merge2Lists(lists[i],lists[i+1]);
                }
                else{
                    lists[j]=lists[i];
                }
                i+=2;
                j++;
            }
            k=j;
        }
        return lists[0];
    }
};