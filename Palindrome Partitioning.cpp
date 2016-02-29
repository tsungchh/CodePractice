class Solution {
public:
    vector<vector<string>> partition(string s) {
        // backtracking, DFS
        vector< vector<string> > result;
        vector<string> ans;
        helper(s, ans, result, 0);
        return result;
    }
    
    void helper(string str, vector<string> answer, vector< vector<string> >& ret, int idx)
    {
        // check if this is the answer, base case
        if(idx == str.size())
        {
            ret.push_back(answer);
            return;
        }
        
        for(int i = idx; i < str.size(); i++)
        {
            string substr = str.substr(idx, i-idx+1);
            if( !isPalindrome(substr) )
                continue;
            answer.push_back(substr);
            helper(str, answer, ret, i+1);
            answer.pop_back();
            
        }
        
        
    }
    
    bool isPalindrome(string str)
    {
        int start = 0;
        int end = str.size()-1;
        while(start < end)
        {
            if(str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

};