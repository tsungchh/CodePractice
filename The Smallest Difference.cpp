class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        // O(n^2) brute force solution, two for loop to iterate all possible
        // situations.
        
        // for certian element in A, find smallest difference with B
        // binary search , target  = 0, then it would find the element close to 0
        int mindiff = INT_MAX;
        
        sort(B.begin(), B.end());
        
        for(int i = 0; i < A.size(); i++)
        {
            int target = A[i];
            
            int closeB = bst(B, target);
            int diff = abs(closeB - target);
            mindiff = diff < mindiff ? diff : mindiff;
        }
        
        return mindiff;
    }
    
    int bst(vector<int>& B, int target)
    {
        int start = 0;
        int end = B.size()-1;
        
        while(start + 1 < end)
        {
            int mid = (start + end) / 2;
            
            if(B[mid] == target)
                return target;
            else if(B[mid] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return abs(B[start]-target) < abs(B[end]-target) ? B[start] : B[end];
    }
};
