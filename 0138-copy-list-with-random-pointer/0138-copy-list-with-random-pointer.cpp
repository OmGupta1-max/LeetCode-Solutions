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
    void insertCopyNode(Node* head){
        Node* temp=head;
        while(temp!=NULL){
           Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    }
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
    Node* connectNext(Node* head){
        Node* dNode=new Node(-1);
        Node* res = dNode;
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            temp->next = copyNode->next;
            res->next = copyNode;
            res = copyNode;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyNode(head);
        connectRandom(head);
        return connectNext(head);
    }
};