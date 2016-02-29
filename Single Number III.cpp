class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        
        int _xor = 0;
        
        for(int i = 0; i < A.size(); i++)
        {
            _xor = _xor ^ A[i];
        }
        
        int rightOneBit =  _xor - ( (_xor-1) & _xor );
        
        int answer1 = 0;
        int answer2 = 0;
        vector<int> answerSet;
        
        for(int i = 0; i < A.size(); i++)
        {
            if( (A[i] & rightOneBit) == 0 )
                answer1 = answer1 ^ A[i];
            else
                answer2 = answer2 ^ A[i];
        }
        
        answerSet.push_back(answer1);
        answerSet.push_back(answer2);
        
        return answerSet;
        
        
    }
};
