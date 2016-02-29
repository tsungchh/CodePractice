class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        
        stack1.push(element);
        // write your code here
    }
    
    void check()
    {
        if( stack2.empty() )
        {
            while( !stack1.empty() )
            {
                int element = stack1.top();
                stack1.pop();
                stack2.push(element);
            }
        }
    }
    
    int pop() {
        
        check();
        int val = stack2.top();
        stack2.pop();
        return val;
        // write your code here
    }

    int top() {
        // write your code here
        check();
        return stack2.top();
    }
};

