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
 // Step 1: Insert copied nodes between original nodes
    void insertCopyNode(Node* head){
        Node* temp=head;
        while(temp!=NULL){
           Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    }
    // Step 2: Connect random pointers
    void connectRandom(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if (temp->random != nullptr) {
            copyNode->random=temp->random->next;}
            else{
            copyNode->random = nullptr;
            }
            temp = copyNode->next;

        }
    }
    // Step 3: Separate original and copied lists
    Node* connectNext(Node* head){
        Node* dNode=new Node(-1);
        Node* res = dNode;
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            temp->next = copyNode->next; // Restore original list
            res->next = copyNode;    // Connect copied list
            res = copyNode;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
         if (head == nullptr) {
            return nullptr;
        }
        insertCopyNode(head);
        connectRandom(head);
        return connectNext(head);
    }
};