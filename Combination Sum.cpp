class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    
    vector<vector<int> > result;
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        if(candidates.size() == 0)
            return result;
            
        sort(candidates.begin(), candidates.end());
            
        vector<int> answer;
        helper(candidates, answer, 0, target);
        
        return result;
    }
    
    void helper(vector<int> &candidates, vector<int> answer, int start, int target)
    {
        if(target == 0)
        {
            result.push_back(answer);
            return;
        }
        else if(target < 0)
        {
            return;
        }
        
        for(int i = start; i < candidates.size(); i++)
        {
            int newTarget = target - candidates[i];
            answer.push_back(candidates[i]);
            helper(candidates, answer, i, newTarget);
            answer.pop_back();
        }
        return;
    }
};
