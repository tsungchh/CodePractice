class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> ans;
        helper(0, 0, n, "", ans);
        return ans;
    }
    
    void helper(int ctOpen, int ctClose, int n, string str, vector<string>& ans)
    {
        //Base case
        
        if(ctClose > ctOpen || ctOpen > n)
            return;
        
        if(ctClose == n)
        {
            ans.push_back(str);
            return;
        }
        
            
        string strAddOpen = str + "(";
        helper(ctOpen+1, ctClose, n, strAddOpen, ans);
        
        string strAddClose = str + ")";
        helper(ctOpen, ctClose+1, n, strAddClose, ans);
        
    }
};
