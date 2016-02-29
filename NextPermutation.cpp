class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        
        // find the first idx which is bigger than previous one
        
        int start = nums.size()-1;
        bool hasIt = false;
        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                int minIdx = i+1;
                for(int j = i+1; j < nums.size(); j++)
                {
                    if(nums[j] > nums[i])
                        minIdx = nums[j] < nums[minIdx] ? j : minIdx;
                }
                
                start = i+1;
                int tmp = nums[minIdx];
                nums[minIdx] = nums[i];
                nums[i] = tmp;
                
                hasIt = true;
                break;
            }
        }
        if(!hasIt)
            reverse(nums);
        
        sort(start, nums.size()-1, nums);
        
    }
    
    void reverse(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    
    void sort(int start, int end, vector<int>& nums)
    {
        for(int i = start; i < nums.size(); i++)
        {
            int minIdx = i;
            for(int j = i; j < nums.size(); j++)
            {
                minIdx = nums[j] < nums[minIdx] ? j : minIdx;
            }
            int tmp = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = tmp;
        }
    }
};
