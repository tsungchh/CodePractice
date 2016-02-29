class Solution {
public:
    int trailingZeroes(int n) {
        
        int num_5 = 0;
        
        while(n > 0)
        {
            n = n / 5;
            num_5 += n;
        }
        
        return num_5;
    }
};