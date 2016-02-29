class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
     
    vector< vector<int> > result;
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        if(nums.size() == 0)
            return result;
        
        vector<bool> visited;
        vector<int> answer;
        
        for(int i=0; i<nums.size(); i++)
        {
            visited.push_back(false);
        }
        
        helper(nums, visited, answer);
        
        return result;
    }
    
    void helper(vector<int> nums, vector<bool> visited, vector<int> ans)
    {
        if(ans.size() == nums.size())
        {
            result.push_back(ans);
        }
        
        for(int i=0; i<visited.size(); i++)
        {
            if(visited[i] == true)
                continue;
            ans.push_back(nums[i]);
            visited[i] = true;
            helper(nums, visited, ans);
            ans.pop_back();
            visited[i] = false;
        }
    }
};

