class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        
        // //O(n) time, O(n) space
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(nums[i]) != map.end())
            {
                map[nums[i]]++;
                if(map[nums[i]] > nums.size()/k)
                    return nums[i];
            }
            else
            {
                map[nums[i]] = 1;
            }
        }
        
        
        
        return -1;
    }
};

