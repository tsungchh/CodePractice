class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        
        stack<int> stk;
        
        for(int i = 0; i < tokens.size(); i++)
        {
            if( isOperator(tokens[i]) )
            {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                int result = 0;
                if(tokens[i] == "+")
                {
                    result = left + right;
                }
                else if(tokens[i] == "-")
                {
                    result = left - right;
                }
                else if(tokens[i] == "*")
                {
                    result = left * right;
                }
                else
                {
                    result = left /right;
                }
                stk.push(result);
                continue;
            }
            else
            {
                int tmpVal = atoi(tokens[i].c_str());
                stk.push(tmpVal);
            }
        }
        
        if(stk.size() > 1)
        {
            return -1;
        }
        
        return stk.top();
        
    }
    
    bool isOperator(string str)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/")
            return true;
        return false;
    }
};





/////////////////////////////

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        
        if(tokens.size() <= 0)
            return 0;
        
        if(tokens.size() == 1)
            return atoi(tokens[0].c_str());
            
        
        while(tokens.size() != 1)
        {
            int i = 0;
            while( !isOperator(tokens[i]) && i < tokens.size() )
            {
                i++;
            }
            int result = 0;
            
            if(tokens[i] == "+")
            {
                result = atoi(tokens[i-2].c_str()) + atoi(tokens[i-1].c_str());
            }
            else if(tokens[i] == "-")
            {
                result = atoi(tokens[i-2].c_str()) - atoi(tokens[i-1].c_str());
            }
            else if(tokens[i] == "*")
            {
                result = atoi(tokens[i-2].c_str()) * atoi(tokens[i-1].c_str());
            }
            else
            {
                result = atoi(tokens[i-2].c_str()) / atoi(tokens[i-1].c_str());
            }
            tokens.erase(tokens.begin()+i);
            tokens.erase(tokens.begin()+i-1);
            tokens.erase(tokens.begin()+i-2);
            tokens.insert(tokens.begin()+i-2, to_string(result));
        }
        
        return atoi(tokens[0].c_str());
    }
    
    bool isOperator(string str)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/")
            return true;
        return false;
    }
};
