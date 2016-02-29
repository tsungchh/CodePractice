class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        // answer shouble be assumed is positive
        
        // //brute solution O(n^3)
        
        // for(int i = 0;i < A.size(); i++)
        // {
        //     for(int j = i; j < A.size(); j++)
        //     {
        //         // compare the max sum O(n), this can be stored
        //     }
        // }
        
        // for each idx, find how far it can go to the left.
        int currSum = 0;
        int maxSum = 0;
        int start = 0;
        int end = 0;
        vector<int> ret(2,A.size()-1);
        for(int i = 0; i < A.size(); i++)
        {
            currSum += A[i];
            if(currSum < 0)
            {
                start = i+1;
                end = i+1;
                currSum = 0;
            }
            else if(currSum  > maxSum)
            {
                end = i;
                ret[0] = start;
                ret[1] = end;
                maxSum = currSum;
            }
        }
        
        
        return ret;
    }
};