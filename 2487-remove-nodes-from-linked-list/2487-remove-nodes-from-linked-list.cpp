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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            // Save next node
            ListNode* next = curr->next;
            // Reverse the connection
            curr->next = prev;
            // Move prev forward
            prev = curr;
            // Move curr forward
            curr = next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);
        // Step 2: First node is always kept
        ListNode* prev = head;
        ListNode* curr = head->next;
        // Maximum value seen so far
        int maxSeen = head->val;
        // Step 3: Process remaining nodes
        while (curr != nullptr) {
            if (curr->val >= maxSeen) {
                // Keep current node
                maxSeen = curr->val;
                prev = curr;
                curr = curr->next;
            } else {
                // Remove current node
                prev->next = curr->next;
                curr = prev->next;
            }
        }
        // Step 4: Reverse back to original order
        head = reverse(head);
        return head;
    }
};