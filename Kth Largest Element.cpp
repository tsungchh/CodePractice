class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        // use quick select alogrithm
        
        return split(0, nums.size()-1, nums, k);
    }
    
    int split(int start, int end, vector<int>& nums, int k)
    {
        // split the array into 3 segments, one with elements bigger, one 
        // smaller, one equal to the pivot element.
        
        int pivot = nums[ (start+end)/2 ];
        int lessIdx = start;
        int greaterIdx = end;
        for(int i = start; i <= end; i++)
        {
            if(i > greaterIdx)
                break;
                
            int val = nums[i];
            
            if(pivot == val)
            {
                continue;
            }
            else if(pivot > val)
            {
                swap(i, lessIdx, nums);
                lessIdx++;
            }
            else
            {
                swap(i, greaterIdx, nums);
                greaterIdx--;
                i--;
            }
        }
        
        //      A    B    C
        // ex. 1234 5555 789
            
        if(nums.size() - greaterIdx > k)
        {
            // C
            return split(greaterIdx+1, end, nums, k);
        }
        else if(nums.size() - lessIdx >= k && nums.size() - greaterIdx <= k )
        {
            // B
            return pivot;
        }
        else
        {
            // A
            return split(start, lessIdx-1, nums, k);
        }
        
    }
    
    void swap(int a, int b, vector<int>& nums)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
};
