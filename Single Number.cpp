class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int answer;
        for(int i = 0; i < A.size(); i++)
        {
            answer = answer ^ A[i];
        }
        
        return answer;
    }
};

