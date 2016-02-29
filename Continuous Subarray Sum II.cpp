class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */

    
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        // 2 situation, one is that the subarray is continuous within the array
        // another one is the subarray that is cut in the middle.
        
        
        vector<int> ret(2, 0);
        if(A.size() < 2)
            return ret;
        int sum = 0;
        int localSum = 0;
        int max = -INT_MAX;
        int start = 0;
        
        // find maximum subarray which continuous.
        for(int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if(localSum < 0)
            {
                start = i;
                localSum = A[i];
            }
            else
            {
                localSum += A[i];
            }
            
            if(localSum > max)
            {
                ret[0] = start;
                ret[1] = i;
                max = localSum;
            }
            
        }
        int min = 0;
        localSum = 0;
        start = 0;
        
        // find subarray which is the minimum subarray, so to find the maximum subarray that is cut in the middle.
        for(int i = 0; i < A.size(); i++)
        {
            if(localSum > 0)
            {
                start = i;
                localSum = A[i];
            }
            else
            {
                localSum += A[i];
            }
            
            
            if( i==0 || i==(A.size()-1) )
                continue;
                    
            if(sum-localSum > max)
            {
                ret[0] = i+1;
                ret[1] = start-1;
                max = sum-localSum;
            }
            
        }
        
        return ret;
    }
};
