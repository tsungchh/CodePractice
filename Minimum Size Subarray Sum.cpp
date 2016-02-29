class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        
        // maintain a window which will have a sum bigger than target(s)
        // windon is consisted with two pointers
        // iterate two pointers to find the solution. O(2*n)
        
        if(nums.size() == 0)
            return -1;
        
        int start = 0;
        int end = 0;
        int sum = nums[0];
        int minLen = INT_MAX;
        
        while( start < nums.size() )
        {
            //extend the end pointer untill the sum is bigger than target(s)
            
            while( sum < s && end < nums.size()-1 )
            {
                end++;
                sum += nums[end]; 
            }
            
            if( sum >= s )
            {
                int newLen = end - start + 1;
                minLen = minLen < newLen ? minLen : newLen;
            }
            
            sum -= nums[start];
            if(end == nums.size()-1 && sum < s)
                break;
            
            start++;
        }
        
        if(minLen == INT_MAX)
            minLen = -1;
            
        return minLen;
        
    }
};
