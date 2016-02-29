class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    vector< vector<string> > answer;
    int totalNQueens(int n) {
        // write your code here
        vector<int> rows;
        helper(rows, n);
        
        return answer.size();
    }
    
    void conver2ans( vector<int> rows )
    {
        vector<string> ans;
        ans.resize(rows.size());
        for(int i = 0; i < rows.size(); i++)
        {
            for(int j = 0; j < rows.size(); j++)
            {
                if(j == rows[i])
                    ans[i] = ans[i] + "Q";
                else
                    ans[i] = ans[i] + ".";
            }
        }
        answer.push_back(ans);
    }
    
    bool isValid( vector<int> rows, int idx )
    {
        for(int i = 0; i < rows.size()-1; i++)
        {
            if(rows[i] == idx)
                return false;
                
            if(rows[i] - idx == rows.size() - 1 - i)
                return false;
                
            if(idx - rows[i] == rows.size() - 1 - i)
                return false;
        }
        return true;
    }
    
    void helper( vector<int> rows, int n )
    {
        if(rows.size() == n)
            conver2ans(rows);
        
        for( int i = 0; i < n; i++ )
        {
            rows.push_back(i);
            if( isValid(rows, i) )
                helper(rows, n);
            rows.pop_back();
        }
    }
};

