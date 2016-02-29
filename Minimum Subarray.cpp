class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        
        // vector<int> localMin(nums.size(), INT_MAX);
        // vector<int> globalMin(nums.size(), INT_MAX);
        
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if( i == 0 )
        //         localMin[i] = nums[i];
        //     else
        //         localMin[i] = localMin[i-1] < 0 ? 
        //                       localMin[i-1] + nums[i] : nums[i];
            
        //     if(i == 0)
        //         globalMin[i] = nums[i];
        //     else
        //         globalMin[i] = globalMin[i-1] < localMin[i] ?
        //                       globalMin[i-1] : localMin[i];
        // }
        
        // return globalMin[globalMin.size()-1];
        
        int sum = 0;
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            min = min < sum ? min : sum;
            if(sum > 0)
            {
                sum = 0;
            }
        }
        
        return min;
    }
};

