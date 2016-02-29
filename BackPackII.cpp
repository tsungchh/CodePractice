class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        // brute force will be 2^N, which N represents A.size()
        // mean we either choose each idx or not.
        
        // subproblem : f[i][j] means for given subset 0:i and size m, 
        // what is its maxmimal value.
        
        // derivation equation: f[i][j] = max( f[i-1][j], f[i-1][j-A[i], -1)
        
        int f[A.size()+1][m+1];
        for(int i = 0 ; i <= A.size(); i++)
        {
            for(int j = 0 ; j <= m; j++)
            {
                f[i][j] = -1;
            }
        }
        
        f[0][0] = 0;
        
        for(int i = 1; i <= A.size(); i++)
        {
            for(int j = 0; j <= m; j++)
            {
                int val = -1;
                if(j-A[i-1] >= 0 && f[i-1][j-A[i-1]] >= 0)
                    val = f[i-1][j-A[i-1]] + V[i-1];
                f[i][j] = f[i-1][j] > val  ? f[i-1][j] : val;
            }
        }
        
        int max = 0;
        for(int j = 0; j <= m; j++)
        {
            max = max > f[A.size()][j] ? max : f[A.size()][j];
        }
        
        return max;
        
    }
};
