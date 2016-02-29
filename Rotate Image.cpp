class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int length = matrix.size();
        int layerSize = (matrix.size()+1) / 2 ;
        int bufferSize = matrix.size()-1;
        for(int i = 0; i < layerSize; i++)
        {
            for(int j = 0; j < bufferSize; j++)
            {
                int tmp = matrix[i][j+i];
                matrix[i][j+i] = matrix[length-1-i-j][i];
                matrix[length-1-i-j][i] = matrix[length-1-i][length-1-i-j];
                matrix[length-1-i][length-1-i-j] = matrix[j+i][length-1-i];
                matrix[j+i][length-1-i] = tmp;
            }
            bufferSize -= 2;
        }
    }
};
