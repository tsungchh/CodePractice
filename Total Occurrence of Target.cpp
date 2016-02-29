class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int totalOccurrence(vector<int>& A, int target) {
        // Write your code here
        // search the left and right bound by using binary search
        
        if(A.size() == 0)
            return 0;
        
        int start = 0;
        int end = A.size()-1;
        
        while(start + 1 < end)
        {
            int mid = (start + end) / 2;
            if(A[mid] < target)
            {
                start = mid;
            }
            else if(A[mid] > target)
            {
                end = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        int left = 0;
        if(A[end] == target)
            left = end;
        if(A[start] == target)
            left = start;
            
        start = 0;
        end = A.size()-1;
        
        while(start + 1 < end)
        {
            int mid = (start + end) / 2;
            if(A[mid] < target)
            {
                start = mid;
            }
            else if(A[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        
        int right = -1;
        
        if(A[start] == target)
            right = start;
        if(A[end] == target)
            right = end;
            
        return right - left + 1;
        
    }
};
