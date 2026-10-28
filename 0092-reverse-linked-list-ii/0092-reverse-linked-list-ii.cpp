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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Dummy node helps when left == 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // beforeLeft will point to the node
        // just before the part we want to reverse
        ListNode* beforeLeft = dummy;
        // Move beforeLeft to position left - 1
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }
        // leftNode is the first node of the
        // portion that we will reverse
        ListNode* leftNode = beforeLeft->next;
        // curr will be used for reversing
        ListNode* curr = leftNode;
        // Standard reversal
        ListNode* prev = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            // Save next node
            ListNode* next = curr->next;
            // Reverse the link
            curr->next = prev;
            // Move prev
            prev = curr;
            // Move curr
            curr = next;
        }
        // prev is now the new head of reversed portion
        ListNode* reversedHead = prev;
        // leftNode became the tail after reversal.
        // curr is the node after the reversed portion.
        beforeLeft->next = reversedHead;
        leftNode->next = curr;
        return dummy->next;
    }
};