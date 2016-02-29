class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        
        vector<int> bits(32, 0);
        int result = 0;
        
        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < A.size(); j++)
            {
                bits[i] += (A[j] >> i) & 1;
                bits[i] = bits[i] % 3;
                
            }
            result |= (bits[i] << i);
        }
        
        return result;
    }
};

