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
    ListNode* reverseKth(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* temp,int k){
        k-=1;
        while(temp!=nullptr&&k>0){
             k--;
             temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=nullptr){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==nullptr){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=nullptr;
            reverseKth(temp);
            if(temp==head){
                head=kthNode;
            }else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};