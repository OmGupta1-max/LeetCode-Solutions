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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Find length
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        // Step 2: Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Step 3: Reach node before target
        temp = dummy;
        for (int i = 0; i < length - n; i++) {
            temp = temp->next;
        }
        // Step 4: Remove target
        temp->next = temp->next->next;
        return dummy->next;
    }
};