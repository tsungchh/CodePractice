class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        
        
        if(board.size() == 0)
            return;
        
        if(board[0].size() == 0)
            return;
        
        for(int i = 0; i < board.size(); i++)
        {
            helper(i, 0, board);
            helper(i, board[0].size()-1, board);
        }
        
        for(int i = 0; i < board[0].size(); i++)
        {
            helper(0, i, board);
            helper(board.size()-1, i, board);
        }
        
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
    }
    
    //DFS
    void helper(int rol, int col, vector<vector<char>>& board) 
    {
        
        if(rol < 0 || rol == board.size())
            return;
            
        if(col < 0 || col == board[0].size())
            return;
            
        if(board[rol][col] == 'X' || board[rol][col] == 'D')
            return;
        
        board[rol][col] = 'D';
        
        helper(rol+1, col, board);
        helper(rol-1, col, board);
        helper(rol, col+1, board);
        helper(rol, col-1, board);
    }
};
