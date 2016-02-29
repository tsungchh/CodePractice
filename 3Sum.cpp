class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ret;
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            
            int start = i+1;
            int end = nums.size()-1;
            
            while(start < end)
            {
                if (start > i + 1 && nums[start - 1] == nums[start]) {
                    start++;
                    continue;
                }
                int sum = nums[start] + nums[end];
                if(sum == target)
                {
                    vector<int> result;
                    result.push_back(nums[i]);
                    result.push_back(nums[start]);
                    result.push_back(nums[end]);
                    sort(result.begin(), result.end());
                    ret.push_back(result);
                    start++;
                }
                else if(sum < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        
        return ret;
        
       
        
    }
};