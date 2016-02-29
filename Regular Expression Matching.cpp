class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        int slen = strlen(s);
        int plen = strlen(p);
        return helper(s, slen-1, p, plen-1);
    }
    
    bool helper(const char *s, int sIdx, const char *p, int pIdx)
    {
        fprintf(stderr, "sIdx = %d, pIdx = %d\n", sIdx, pIdx);
        if(sIdx == -1)
        {
            if(pIdx == -1)
                return true;
            else if(p[pIdx] == '*')
                return helper(s, sIdx, p, pIdx-2);
        }
        
        if(pIdx == -1)
            return false;
        
        if(s[sIdx] == p[pIdx] || p[pIdx] == '.')
            return helper(s, sIdx-1, p, pIdx-1);
        
        if(p[pIdx] == '*')
        {
            if(p[pIdx-1] == s[sIdx] || p[pIdx-1] == '.')
            {
                bool ret = false;
                ret = helper(s, sIdx, p, pIdx-2);
                int tmp = sIdx;
                while(tmp >= 0 && (s[tmp] == s[sIdx] || p[pIdx-1] == '.') )
                {
                    tmp--;
                    ret = ret || helper(s, tmp, p, pIdx-2);
                }
                return ret;
            }
            else if(p[pIdx-1] != s[sIdx])
            {
                return helper(s, sIdx, p, pIdx-2);   
            }
        }
        
        return false;
    }
};



// dp solution

public boolean isMatch(String s, String p) {
    int sL=s.length(), pL=p.length();

    boolean[][] dp = new boolean[sL+1][pL+1];
    dp[0][0] = true; // If s and p are "", isMathch() returns true;

    for(int i=0; i<=sL; i++) {

        // j starts from 1, since dp[i][0] is false when i!=0;
        for(int j=1; j<=pL; j++) {
            char c = p.charAt(j-1);

            if(c != '*') {
                // The last character of s and p should match;
                // And, dp[i-1][j-1] is true;
                dp[i][j] = i>0 && dp[i-1][j-1] && (c=='.' || c==s.charAt(i-1));
            }
            else {
                // Two situations:
                // (1) dp[i][j-2] is true, and there is 0 preceding element of '*';
                // (2) The last character of s should match the preceding element of '*';
                //     And, dp[i-1][j] should be true;
                dp[i][j] = (j>1 && dp[i][j-2]) ||
                           (i>0 && dp[i-1][j] && (p.charAt(j-2)=='.' || p.charAt(j-2)==s.charAt(i-1)));
            }
        }
    }

    return dp[sL][pL];
}