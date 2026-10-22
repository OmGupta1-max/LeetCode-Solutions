// Time = O(N x 2 x log-N)
// Space = O(N)

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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>mpp;
        ListNode* temp = head;
        while(temp!=NULL){
            if(mpp.count(temp))
            return true;
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;

    }
};
