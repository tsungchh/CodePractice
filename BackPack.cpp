class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        
        if(A.size() == 0)
            return 0;
        
        // state f[i][j], which means whether it has size j from element 0 
        // to element i.
        
        // derivated equation, f[i][j] = f[i-1][j] || f[i-1][ j-A[i] ]
        
        // initialization
        vector< vector<bool> > f( A.size() );
        for(int i = 0; i < f.size(); i++)
        {
            f[i].resize(m+1, false);
            f[i][0] = true;
        }
        
        if(A[0] <= m )
            f[0][A[0]] = true;
        
        for(int i = 1; i < f.size(); i++)
        {
            for(int j = 1; j < f[i].size(); j++)
            {
                f[i][j] = f[i-1][j] || (j >= A[i] ? f[i-1][j-A[i]] : false);
            }
        }
        
        for(int i = m; i >= 0; i--)
        {
            if( f[f.size()-1][i] )
                return i;
        }
        
        return 0;
    }
};
