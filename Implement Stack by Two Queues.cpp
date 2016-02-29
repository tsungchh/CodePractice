class Stack {
public:
    // Push a new item into the stack
    void push(int x) {
        // Write your code here
        _top = x;
        q1.push(x);
    }

    // Pop the top of the stack
    void pop() {
        
        while(!q1.empty())
        {
            int tmp = q1.front();
            q1.pop();
            if( !q1.empty() )
                q2.push(tmp);
        }
        
        while(!q2.empty())
        {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            if(q2.empty())
                _top = tmp;
        }
        // Write your code here
    }

    // Return the top of the stack
    int top() {
        // Write your code here
        return _top;
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        // Write your code here
        q1.empty();
    }
    
private:
    
    int _top;
    queue<int> q1;
    queue<int> q2;
};


