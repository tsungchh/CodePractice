class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        
        int max = 0;
        //O(n^3)
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                int area = search(i, j, matrix);
                max = max > area ? max : area;
            }
        }
        
        return max;
    }
    
    
    // This part can be optimized by using dynamic programming
    int search(int iIdx, int jIdx, vector< vector<int> >& matrix)
    {
        int width = 1;
        int area = 0;
        while(iIdx + width -1 < matrix.size() && jIdx + width -1 < matrix[0].size())
        {
            for(int i = iIdx; i < iIdx+width; i++)
            {
                if(matrix[i][jIdx+width-1] == 0)
                    return area;
            }
            
            for(int j = jIdx; j < jIdx+width; j++)
            {
                if(matrix[iIdx+width-1][j] == 0)
                    return area;
            }
            
            area = width*width;
            width++;
            
        }
        
        return area;
    }
};
