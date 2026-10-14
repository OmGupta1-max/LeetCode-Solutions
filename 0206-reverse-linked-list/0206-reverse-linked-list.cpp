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
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        // Store values
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        // Reverse values
        reverse(arr.begin(), arr.end());
        // Put values back
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};