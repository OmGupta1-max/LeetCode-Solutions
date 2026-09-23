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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node helps us easily build the answer list
        ListNode* dummy = new ListNode(0);
        // tail always points to the last node of our answer
        ListNode* tail=dummy;
        int carry = 0;
        // Continue while there are digits or a carry
        while(l1!=nullptr||l2!=nullptr||carry!=0){
            // Get current digits
            int x = (l1!=nullptr) ? l1->val:0;
            int y = (l2!=nullptr) ? l2->val:0;
            // Add digits and carry
            int sum=carry+x+y;
            // Extract digit and carry
             int digit = sum%10;
             carry = sum/10;
             // Create answer node
            ListNode* newNode = new ListNode(digit);
            // Attach it to answer list

            tail->next=newNode;
            tail=newNode;
            // move l1
            if(l1!=nullptr){
                l1 = l1->next;
            }
            // move l2
            if(l2!=nullptr){
                l2 = l2->next;
            }
        }
        // skip dummy node
       return dummy->next;
    }
};