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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (ListNode* head : lists) {
            ListNode* temp = head;
            while (temp != nullptr) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int val : arr) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy->next;
    }
};