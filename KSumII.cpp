class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        // DFS
        vector<int> ans;
        vector< vector<int> >result;
        helper(0, ans, result, target, A, k);
        return result;
    }
    
    void helper(int idx, vector<int> ans, vector< vector<int> >& result, 
                int target, vector<int> A, int k)
    {
        if( ans.size() == k && target == 0 )
        {
            result.push_back(ans);
            return;
        }
        
        for(int i = idx; i < A.size(); i++)
        {
            if(target-A[i] < 0)
                continue;
            ans.push_back(A[i]);
            helper(i+1, ans, result, target-A[i], A, k);
            ans.pop_back();
        }
    }
};

