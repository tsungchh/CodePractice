class Solution {
public:
    int minDistance(string word1, string word2) {
        
        //first brute solution
        //return recur(word1, word2, 0, 0);
        
        // dynamic programming solution
        
        return dpSolution(word1, word2);
    }
    
    int dpSolution(string word1, string word2)
    {
        int f[word1.size()+1][word2.size()+1];
        
        for(int i = 0; i < word1.size()+1; i++)
        {
            f[i][0] = i;
        }
        for(int i = 0; i < word2.size()+1; i++)
        {
            f[0][i] = i;
        }
        
        for(int i = 1; i < word1.size()+1; i++)
        {
            for(int j = 1; j < word2.size()+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    f[i][j] = f[i-1][j-1];
                }
                else
                {
                    int del = f[i-1][j]+1;
                    int insert = f[i][j-1]+1;
                    int replace = f[i-1][j-1]+1;
                    
                    int min = del < insert ? del : insert;
                    min = min < replace ? min : replace;
                    f[i][j] = min;
                }
            }
        }
        
        return f[word1.size()][word2.size()];
        
    }
    
    
    int recur(string word1, string word2, int idx1, int idx2)
    {
        //base case
        if(idx1 == word1.size() && idx2 == word2.size())
            return 0;
        if(idx1 == word1.size())
            return word2.size() - idx2;
        if(idx2 == word2.size())
            return word1.size() - idx1;
        
        
        // if equal
        if(word1[idx1] == word2[idx2])
        {
            return recur(word1, word2, idx1+1, idx2+1);
        }
        else
        {
            int del = recur(word1, word2, idx1+1, idx2);
            int insert = recur(word1, word2, idx1, idx2+1);
            int replace = recur(word1, word2, idx1+1, idx2+1);
            
            int min = del < insert ? del : insert;
            min = min < replace ? min : replace;
            return min;
        }
    }
};