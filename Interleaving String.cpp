class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // brute force solution using recursion.
        //return rec(s1, s2, s3, 0, 0, 0);
        
        // dp version
        return dp(s1, s2, s3);
    }
    
    bool dp(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        bool f[s1.size()+1][s2.size()+1];
        
        f[0][0] = true;
        
        for(int i = 1; i <= s1.size(); i++)
        {
            f[i][0] = s1[i-1] == s3[i-1] ? f[i-1][0] : false; 
        }
        
        for(int i = 1; i <= s2.size(); i++)
        {
            f[0][i] = s2[i-1] == s3[i-1] ? f[0][i-1] : false; 
        }
        
        for(int i = 1; i <= s1.size(); i++)
        {
            for(int j = 1; j <= s2.size(); j++)
            {
                bool s1Try = s3[i+j-1] == s1[i-1] ? f[i-1][j] : false;
                bool s2Try = s3[i+j-1] == s2[j-1] ? f[i][j-1] : false;
                
                f[i][j] = s1Try || s2Try;
            }
        }
        
        return f[s1.size()][s2.size()];
        
    }
    
    bool rec(string s1, string s2, string s3, int idx1, int idx2, int idx3)
    {
        if(idx3 == s3.size())
            return true;
            
        if(idx2 == s2.size())
        {
            return s3[idx3] == s2[idx2] ? rec(s1, s2, s3, idx1, idx2+1, idx3+1) : false; 
        }
        
        if(idx1 == s1.size())
        {
            return s3[idx3] == s1[idx1] ? rec(s1, s2, s3, idx1+1, idx2, idx3+1) : false;
        }
            
        if(s3[idx3] != s1[idx1] && s3[idx3] != s2[idx2])
            return false;
        
        bool s1Try = s3[idx3] == s1[idx1] ? rec(s1, s2, s3, idx1+1, idx2, idx3+1) : false;
        bool s2Try = s3[idx3] == s2[idx2] ? rec(s1, s2, s3, idx1, idx2+1, idx3+1) : false;
        
        return s1Try || s2Try;
    }
};