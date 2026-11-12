// Time = O(2N)
// Space = O(2N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        // Step 1: Create copies of all nodes
        Node* temp = head;
        while (temp != nullptr) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        // Step 2: Connect next and random pointers
        temp = head;
        while (temp != nullptr) {
            Node* copy = mp[temp];
            copy->next = mp[temp->next];
            copy->random = mp[temp->random];
            temp = temp->next;
        }
        // Step 3: Return copied head
        return mp[head];
    }
};
