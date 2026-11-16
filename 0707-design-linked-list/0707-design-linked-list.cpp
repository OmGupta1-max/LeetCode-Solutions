class MyLinkedList {
public:
    class Node {
    public:
        int val;
        Node* next;

        Node(int value) {
            val = value;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head=NULL;
        tail=NULL;
        size=0;

    }
    
    int get(int index) {
        if(index<0||index>=size)
        return -1;
        Node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        if(tail==NULL){
            tail=newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode= new Node(val);
        if(head==NULL){
            tail=newNode;
            head=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size)
        return;
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
         if (index < 0 || index >= size)
            return;
         if (index == 0) {
            Node* deleteNode = head;
            head = head->next;    
        delete deleteNode;
            size--;
            if(head==NULL){
                tail=NULL;
            }
            return;
        }    
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        if(deleteNode==tail){
            tail=temp;
        }
        delete deleteNode;
        size--;
    }      
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */