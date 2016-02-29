class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int>> mem;
        vector<vector<int>> ret;
        ret.resize(2);
        ret[0].resize(2, 0);
        ret[1].resize(2, 0);
        
        
        // initiale it 
        int height = matrix.size();
        int width = matrix[0].size();
        
        mem.resize(height+1);
        // mem[i][j] means sum(0, 0 to i, j)
        for( int i=0; i<=height; i++) 
        {
            mem[i].resize(width+1);
            mem[i][0] = 0;
        }
        
        for(int i = 0; i <= width; i++)
        {
            mem[0][i] = 0;
        }
         
        for(int i=1; i<=height; i++)
        {
            for(int j=1; j<=width; j++)
            {
                mem[i][j] = mem[i][j-1] + mem[i-1][j] - mem[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        for(int l = 0; l < height; l++)
        {
            for(int h = l+1; h <= height; h++)
            {
                unordered_map<int, int> map;
                
                for(int i = 0; i <= width; i++)
                {
                    int diff = mem[h][i] - mem[l][i];
                    //   5 6 1 2 -1 -2  4
                    // 0 1 2 3 4  5  6  7
                    //  
                    if(map.find(diff) != map.end())
                    {
                        int left = map[diff];
                        int right = i;
                        ret[0][0] = l;
                        ret[0][1] = left;
                        ret[1][0] = h-1;
                        ret[1][1] = right-1;
                        return ret;
                    }
                    else
                    {
                        map[diff] = i;
                    }
                }
            }
        }
        
        fprintf(stderr, "%d %d, %d %d\n", ret[0][0], ret[0][1], ret[1][0], ret[1][1]);
        
        return ret;
    }
    
};



