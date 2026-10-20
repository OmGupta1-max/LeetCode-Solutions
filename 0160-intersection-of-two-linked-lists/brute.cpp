// Time = O(n + m)
// Space = O(m) - unordered_set

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // Store addresses of all nodes of List A
        unordered_set<ListNode*> st;
        ListNode* temp = headA;
        while (temp != nullptr) {
            st.insert(temp);       // Store the node itself
            temp = temp->next;
        }
        // Traverse List B
        temp = headB;
        while (temp != nullptr) {
            // Check whether the same node exists in List A
            if (st.find(temp) != st.end()) {
                return temp;
            }
            temp = temp->next;
        }
        // No intersection
        return nullptr;
    }
};
