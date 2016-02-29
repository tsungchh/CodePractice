class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        
        int count = 0;
        int candidate = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if( count == 0 )
            {
                count++;
                candidate = nums[i];
            }
            else if( candidate == nums[i] )
                count++;
            else
                count--;
        }
        
        return candidate;
        
    }
};

