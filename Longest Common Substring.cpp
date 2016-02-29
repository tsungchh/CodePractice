class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        
        int sizeA = A.size();
        int sizeB = B.size();
        
        int f[sizeA+1][sizeB+1];
        
        for( int i = 0; i <= sizeA; i++ )
            f[i][0] = 0;
            
        for( int i = 0; i <= sizeB; i++ )
            f[0][i] = 0;
            
        int max = 0;
        for( int i = 1; i <= sizeA; i++)
        {
            
            for(int j = 1; j <= sizeB; j++)
            {
                
                if(A[i-1] == B[j-1])
                    f[i][j] = f[i-1][j-1] + 1;
                else
                    f[i][j] = 0;
                    
                max = max > f[i][j] ? max : f[i][j];
                
            }
        }
        
        
        
        return max;
    }
};

