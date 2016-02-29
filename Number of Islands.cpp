class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    count++;
                    setVisited(i, j, grid);
                }
            }
        }
        return count;
    }
    
    void setVisited(int row, int col, vector<vector<bool>>& grid)
    {
        if( row < 0 || row >= grid.size() )
            return;
        
        if( col < 0 || col >= grid[0].size() )
            return;
        
        if( grid[row][col] == 0 )
            return;
        
        if(grid[row][col] == 1)
            grid[row][col] = 0;
        
        setVisited(row+1, col, grid);
        setVisited(row-1, col, grid);
        setVisited(row, col+1, grid);
        setVisited(row, col-1, grid);
    }
};
