class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        
        // vector<int> localMax(nums.size(), INT_MIN);
        // int globalMax = INT_MIN;
        // for(int i = 0; i < nums.size(); i ++)
        // {
        //     if(i == 0)
        //         localMax[i] = nums[i];
        //     else
        //         localMax[i] = localMax[i-1] > 0 ? 
        //                       localMax[i-1] + nums[i] : nums[i];
                              
        //     if(i == 0)
        //         globalMax = nums[i];
        //     else
        //         globalMax = globalMax > localMax[i] ? 
        //                     globalMax : localMax[i];
        // }
        
        // return globalMax;
        int max = -INT_MAX;
        int sum = 0;
        int startIdx = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            max = max > sum ? max : sum;
            if(sum < 0)
            {
                sum = 0;
            }
        }
        
        return max;
    }
};


//Divide and conquer solution

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n==0) return 0;
        return maxSubArrayHelperFunction(A,0,n-1);
    }

    int maxSubArrayHelperFunction(int A[], int left, int right) {
        if(right == left) return A[left];
        int middle = (left+right)/2;
        int leftans = maxSubArrayHelperFunction(A, left, middle);
        int rightans = maxSubArrayHelperFunction(A, middle+1, right);
        int leftmax = A[middle];
        int rightmax = A[middle+1];
        int temp = 0;
        for(int i=middle;i>=left;i--) {
            temp += A[i];
            if(temp > leftmax) leftmax = temp;
        }
        temp = 0;
        for(int i=middle+1;i<=right;i++) {
            temp += A[i];
            if(temp > rightmax) rightmax = temp;
        }
        return max(max(leftans, rightans),leftmax+rightmax);
    }
};

