
class Dequeue {
public:    
    
    struct ListNode {
        ListNode* next;
        ListNode* prev;
        int val;
        ListNode(int _val)
        {
            val = _val;
            next = NULL;
            prev = NULL;
        }
        ~ListNode(){}
    };
    
    Dequeue() {
        root = new ListNode(-1);
        tail = new ListNode(-1);
        root->next = tail;
        tail->prev = root;
        // do initialize if necessary
    }

    void push_front(int item) {
        ListNode* newNode = new ListNode(item);
        newNode->next = root->next;
        newNode->prev = root;
        root->next->prev = newNode;
        root->next = newNode;
        // Write your code here
    }

    void push_back(int item) {
        ListNode* newNode = new ListNode(item);
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;        
        // Write your code here
    }

    int pop_front() {
        ListNode* delNode = root->next;
        int val = delNode->val;
        
        //do deletion
        root->next = delNode->next;
        delNode->next->prev = root;
        delete delNode;
        return val;
        // Write your code here
    }

    int pop_back() {
        ListNode* delNode = tail->prev;
        int val = delNode->val;
        
        //do deletion
        tail->prev = delNode->prev;
        delNode->prev->next = tail;
        delete delNode;
        return val;
        // Write your code here
    }

private:
    ListNode* tail;
    ListNode* root;
};
	
