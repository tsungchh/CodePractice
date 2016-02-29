class Solution {
public:
    int numDistinct(string s, string t) {
        
        // recursion solution
        // return rec(s, t, s.size()-1, t.size()-1);
        
        // dynamic programming
        return dpSolu(s, t);
    }
    
    int dpSolu(string s, string t)
    {
        int f[s.size()+1][t.size()+1];
        
        for(int i = 0; i <= t.size(); i++)
        {
            f[0][i] = 0;
        }
        
        
        for(int i = 0; i <= s.size(); i++)
        {
            f[i][0] = 1;
        }
        
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                if(s[i-1] == t[j-1])
                {
                    f[i][j] = f[i-1][j-1] + f[i-1][j];
                }
                else
                {
                    f[i][j] = f[i-1][j];
                }
            }
        }
        
        return f[s.size()][t.size()];
        
    }
    
    int rec(string s, string t, int sIdx, int tIdx)
    {
        //base case
        if(tIdx < 0)
            return 1;
        if(sIdx < 0)
            return 0;
        
        if(s[sIdx] == t[tIdx])
        {
            return rec(s, t, sIdx-1, tIdx-1) + rec(s, t, sIdx-1, tIdx);
        }
        else
        {
            return rec(s, t, sIdx-1, tIdx);
        }
    }
};