class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        
        
        if(board.size() == 0)
            return false;
        if(board.size() != board[0].size())
            return false;
        
        // check for every col and row
        for(int i = 0; i < board[0].size(); i++)
        {
            if( !isValid(i, i, board) )
                return false;
        }
        
        // check for every nearby 9 cells
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                // create set
                vector<bool> set(9, false);
                int colstart = 3*i;
                int colend = 3*(i+1);
                
                int rowstart = 3*j;
                int rowend = 3*(j+1);
                for(int k = colstart; k < colend; k++)
                {
                    for(int j = rowstart; j < rowend; j++)
                    {
                        if(board[j][k] != '.')
                        {
                            
                            int element = board[j][k] - '1';
                            if(set[element] == true)
                            {   
                                return false;
                            }
                            set[element] = true;
                        }
                    }
                }
                
            }
        }
        
        return true;
    }
    
    bool isValid(int row, int col, const vector<vector<char>> & board)
    {
        vector<bool> set(9, false);
        vector<bool> setCol(9, false);
        for(int i = 0; i < board[0].size(); i++)
        {
            if(board[row][i] != '.')
            {            
                int tmp = board[row][i] - '1';
                if(tmp >= 9 || tmp < 0)
                    return false;
                    
                if(set[tmp] == true)
                    return false;
                else
                    set[tmp] = true;
            }
            
            if(board[i][col] != '.')
            {
                int tmpCol = board[i][col] - '1';
                if(tmpCol >= 9 || tmpCol < 0)
                    return false;
                
                if(setCol[tmpCol])
                    return false;
                else
                    setCol[tmpCol] = true;
            }
        }
        
        return true;
    }
};