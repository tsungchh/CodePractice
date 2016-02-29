class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        
        int sizeA = A.size();
        int sizeB = B.size();
        
        int f[sizeA+1][sizeB+1];
        
        for( int i = 0; i <= sizeA; i++ )
            f[i][0] = 0;
            
        for( int i = 0; i <= sizeB; i++ )
            f[0][i] = 0;
            
        
        for( int i = 1; i <= sizeA; i++ )
        {
            for( int j = 1; j <= sizeB; j++ )
            {
                
                f[i][j] = f[i-1][j] > f[i][j-1] ? 
                          f[i-1][j] : f[i][j-1];
                
                if(A[i-1] == B[j-1])
                {
                    f[i][j] = (f[i-1][j-1] + 1) > f[i][j] ? (f[i-1][j-1] + 1) : f[i][j] ;
                }
            }
        }
        
        return f[sizeA][sizeB];
    }
};

