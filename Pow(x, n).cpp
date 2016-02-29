class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        
        return helper2(x, n);
    }
    
    // solution 1, take O(n)
    double helper(double x, int n)
    {
        if( n == 0)
            return 1;
        
        if( n < 0)
        {
            return helper(x, n+1) / x;
        }
        else if (n > 0)
        {
            return x * helper(x, n-1);
        }
        
        return 1;
    }
    
    
    double helper2(double x, int n)
    {
        if( n == 1 )
            return x;
        else if( n == -1)
            return 1/x;
        
        if( n > 0)
        {
            if(n % 2 == 0) // even
            {
                double ret = helper(x, n/2);
                return ret*ret;
            }
            else // odd
            {
                // e.g n = 9, 4*4*1
                double ret = helper(x, n/2);
                return ret*ret*x;
            }
        }
        else if( n < 0)
        {
            if(n % 2 == 0) // even
            {
                double ret = helper(x, n/2);
                return ret*ret;
            }
            else
            {
                double ret = helper(x, n/2);
                return (ret*ret)/x;
            }
        }
        
        return 1;
        
    }
    
};