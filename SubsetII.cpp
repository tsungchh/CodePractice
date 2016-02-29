class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > result;
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        
        vector<int> answer;
        vector<int> sortedS;
        for(int i = 0; i < S.size(); i++)
        {
            sortedS.push_back(S[i]);
        }
        sort(sortedS.begin(), sortedS.end());
        //sortedS = bubbleSort( S );
        helper(sortedS, 0, answer);
        
        return result;
    }
    
    vector<int> bubbleSort(const vector<int>& array)
    {
        int n = array.size();
        int swap;
        vector<int> result;
        
        for(int i=0; i<n; i++)
        {
            result.push_back(array[i]);
        }
        
          for (int c = 0 ; c < ( n - 1 ); c++)
          {
            for (int d = 0 ; d < n - c - 1; d++)
            {
              if (result[d] > result[d+1]) /* For decreasing order use < */
              {
                swap       = result[d];
                result[d]   = result[d+1];
                result[d+1] = result[d];
              }
            }
          }
    }
    
    void helper(vector<int>& S, int idx, vector<int> ans)
    {
        
        result.push_back(ans);
        
        //int prev = S.size() > 0 ? S[0] : 0;
        
        for( int i = idx; i < S.size(); i++ )
        {
            if( i > 0 && i != idx && S[i-1] == S[i] )
                continue;
            ans.push_back( S[i] );
            //prev = S[i];
            helper(S, i+1, ans);
            ans.pop_back();
        }
    }
};

