class Solution {
public:
    /**
     * @param stk an integer stack
     * @return void
     */
    void stackSorting(stack<int>& stk) {
        // Write your code here
        
        // 1 st solution
        // pop all elements into array
        // sort that array, and put it back to stk
        
        
        // 2nd solution
        
        stack<int> stk2;
        
        int len = stk.size();
        
        while(len != 0)
        {
            int min = INT_MAX;
            int popLen = len;
            while(popLen != 0)
            {
                min = stk.top() < min ? stk.top() : min;
                stk2.push(stk.top());
                stk.pop();
                popLen--;
            }
            
            stk.push(min);
            bool pushMin = false;
            
            while(!stk2.empty())
            {
                if( !pushMin && min == stk2.top() )
                {
                    pushMin = true;
                }
                else
                {
                    stk.push(stk2.top());
                }
                stk2.pop();
            }
            len--;
        }
    }
};