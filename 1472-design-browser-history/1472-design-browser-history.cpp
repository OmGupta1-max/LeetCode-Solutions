class BrowserHistory {
public:
    class Node {
    public:
        string val;
        Node* next;
        Node* back;

        Node(string url) {
            val = url;
            next = nullptr;
            back = nullptr;
        }
    };
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currentPage->next=newNode;
        newNode->back=currentPage;
        currentPage=newNode;
        
    }
    
    string back(int steps) {
        while(steps){
            if(currentPage->back)
            currentPage=currentPage->back;
            else break;
            steps--;
        }
        return currentPage->val;
    }
    
    string forward(int steps) {
        while(steps){
            if(currentPage->next)
            currentPage=currentPage->next;
            else
            break;
            steps--;
        }
        return currentPage->val; 
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */