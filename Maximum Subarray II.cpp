class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    struct Pair {
        int max;
    }; 
     
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        
        vector<Pair> leftSub;
        leftSub.resize(nums.size());
        vector<int> localMax;
        localMax.resize(nums.size());
        localMax[0] = nums[0];
        leftSub[0].max = nums[0];
        int max = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
        
            localMax[i] = localMax[i-1] + nums[i] > nums[i] ? 
                          localMax[i-1] + nums[i] : nums[i];
                          
            max = max > localMax[i] ? max : localMax[i];
            
            leftSub[i].max = max;
        }
        
        max = nums[nums.size()-1];
        vector<Pair> rightSub;
        rightSub.resize(nums.size());
        localMax.resize(nums.size());
        localMax[nums.size()-1] = nums[nums.size()-1];
        rightSub[nums.size()-1].max = nums[nums.size()-1];
        
        for(int i = nums.size()-2; i >= 0; i--)
        {
        
            localMax[i] = localMax[i+1] + nums[i] > nums[i] ? 
                          localMax[i+1] + nums[i] : nums[i];
                          
            max = max > localMax[i] ? max : localMax[i];
            
            rightSub[i].max = max;
        }
        
        max = INT_MIN;
        
        for(int i = 0; i < nums.size()-1; i++)
        {
            //0->i, i+1->nums.size()-1
            int max1 = leftSub[i].max + rightSub[i+1].max;
            
            max = max1 > max ? max1 : max;
        }
        
        return max;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        
        vector<int> leftMax;
        vector<int> rightMax;
        
        int sum = 0;
        int max = -INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            max = max > sum ? max : sum;
            if(sum < 0)
            {
                sum = 0;
            }
            leftMax.push_back(max);
        }
        
        sum = 0;
        max = -INT_MAX;
        rightMax.resize(nums.size());
        for(int i = nums.size()-1; i >= 0; i--)
        {
            sum += nums[i];
            max = max > sum ? max : sum;
            if(sum < 0)
            {
                sum = 0;
            }
            rightMax[i] = max;
        }
        max = -INT_MAX;
        for(int i = 1; i < nums.size(); i++)
        {
            int max_tmp = leftMax[i-1] + rightMax[i];
            max = max > max_tmp ? max : max_tmp;
        }
        
        return max;
    }
};



