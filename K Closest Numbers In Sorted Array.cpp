class Solution {
public:
    /**
     * @param A an integer array
     * @param target an integer
     * @param k a non-negative integer
     * @return an integer array
     */
    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        // Write your code here
        
        int start = 0;
        int end = A.size()-1;
        while(start + 1 < end)
        {
            int mid = (start + end) / 2;
            if(A[mid] == target)
            {
                start = mid;
                break;
            }
            else if(A[mid] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        int closeIdx = -1;
        if(abs(A[start] - target) < abs(A[end] - target))
        {
            closeIdx = start;
        }
        else
        {
            closeIdx = end;
        }
        
        int front = closeIdx;
        int tail = closeIdx-1;
        
        int ct = 0;
        vector<int> ret;
        while(ct < k && front < A.size() && tail >= 0)
        {
            if(abs(A[front] - target) < abs(A[tail] - target))
            {
                ret.push_back(A[front]);
                front++;
            }
            else
            {   
                ret.push_back(A[tail]);
                tail--;
            }
            ct++;
        }
        
        while(ct < k && front < A.size())
        {
            ret.push_back(A[front]);
            front++;
            ct++;
        }
        
        while(ct < k && tail >= 0)
        {
            ret.push_back(A[tail]);
            tail--;
            ct++;
        }
        
        
        return ret;
    }
};