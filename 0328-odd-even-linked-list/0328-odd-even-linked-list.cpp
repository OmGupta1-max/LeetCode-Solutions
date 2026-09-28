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
    ListNode* oddEvenList(ListNode* head) {
        // Empty list or only one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        // Save the beginning of the even chain
        ListNode* evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            // Connect current odd node to next odd node
            odd->next = even->next;
            // Connect current even node to next even node
            even->next = even->next->next;
            // Move both pointers
            odd = odd->next;
            even = even->next;
        }
        // Attach even chain after odd chain
        odd->next = evenHead;
        return head;
    }
};