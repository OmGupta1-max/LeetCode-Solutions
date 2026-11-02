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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummySmall=new ListNode(0);
        ListNode* dummyLarge=new ListNode(0);
        ListNode* small=dummySmall;
        ListNode* large=dummyLarge;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=NULL;
            if(curr->val<x){
                small->next=curr;
                small=curr;
            }
            else{
                large->next=curr;
                large=curr;
            }
            curr=next;
        }
        small->next=dummyLarge->next;
        return dummySmall->next;
    }
};