class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        // brute force
        // sort(nums.begin(), nums.end());
        // return nums[(nums.size()-1) / 2];
        //quicksort
        
        return quickSelect(0, nums.size()-1, nums, (nums.size()-1)/2);
        
    }
    
    int quickSelect(int start, int end, vector<int>& nums, int lessNum)
    {
        int mid = (start + end) / 2;
        int pivot = nums[mid];
    
        int l = start;
        int r = end;
    
        while( true )
        {
            while(nums[l] < pivot && l < nums.size())
            {
                l++;
            }
            while(nums[r] >= pivot && r >= 0)
            {
                r--;
            }
            
            if(l > r)
                break;
            
            swap(nums, l, r);
            
        }
        
        /*Doing this in case the pivot is the minimum or maximum element of the array*/
        if( l <= mid)
            swap(nums, l, mid);
        else
            swap(nums, r, mid);
            
        if(l == lessNum)
        {
            return pivot;
        }
        else if(l < lessNum)
        {
            return quickSelect(l+1, end, nums, lessNum);    
        }
        else
        {
            return quickSelect(start, l-1, nums, lessNum);
        }
    }
    
    void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};

