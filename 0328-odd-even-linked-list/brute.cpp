// Time = O(N)
// Space = O(N) + O(N) = O(2N) = O(N)

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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        vector<int> odd;
        vector<int> even;

        ListNode* temp = head;
        int position = 1;

        // Separate values
        while (temp != nullptr) {

            if (position % 2 == 1) {
                odd.push_back(temp->val);
            } else {
                even.push_back(temp->val);
            }

            temp = temp->next;
            position++;
        }

        // Put odd values first
        temp = head;

        for (int x : odd) {
            temp->val = x;
            temp = temp->next;
        }

        // Put even values after odd values
        for (int x : even) {
            temp->val = x;
            temp = temp->next;
        }

        return head;
    }
};
