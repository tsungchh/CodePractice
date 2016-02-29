class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > result;
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	// dfs 
    	result.resize(0);
    	vector<int> answer;
    	answer.resize(0);
    	result.push_back(answer);
    	
    	helper(nums, answer, 0);
    	return result;
    }
    
    void helper(vector<int>& nums, vector<int> answer, int idx)
    {
        if(idx == nums.size())
        {
            //result.push_back(answer);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++)
        {
            answer.push_back(nums[i]);
            helper(nums, answer, i+1);
            result.push_back(answer);
            answer.pop_back();
        }
    }
};
