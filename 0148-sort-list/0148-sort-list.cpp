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
    ListNode* sortList(ListNode* head) {
         vector<int> arr;

        // Step 1: Copy node values into a vector
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Sort the vector
        sort(arr.begin(), arr.end());

        // Step 3: Write sorted values back
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