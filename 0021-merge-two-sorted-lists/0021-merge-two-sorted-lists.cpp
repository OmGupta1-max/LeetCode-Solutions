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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        // Take values from list1
        ListNode* temp1 = list1;
        while (temp1 != nullptr) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }
        // Take values from list2
        ListNode* temp2 = list2;
        while (temp2 != nullptr) {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }
        // Sort all values
        sort(arr.begin(), arr.end());
        // Create the merged linked list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for (int i = 0; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
};