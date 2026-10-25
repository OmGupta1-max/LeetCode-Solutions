// Time = O(n^2) - TLE
// Space = O(1)

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            // Check whether there is a greater node
            // somewhere to the right of curr
            ListNode* right = curr->next;
            bool remove = false;
            while (right != nullptr) {
                if (right->val > curr->val) {
                    remove = true;
                    break;
                }
                right = right->next;
            }
            // If a greater node exists, remove curr
            if (remove) {
                if (prev == nullptr) {
                    // curr is the head
                    head = curr->next;
                    curr = head;
                }
                else {
                    // Skip curr
                    prev->next = curr->next;
                    curr = prev->next;
                }
            }
            else {
                // Keep curr
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
