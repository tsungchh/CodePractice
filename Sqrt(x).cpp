class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        
        if( x == 0 || x == 1)
            return x;
        
        int start = 0;
        int end = x/2 < std::sqrt(INT_MAX)? x/2+1:std::sqrt(INT_MAX);  
        
        while(start + 1 < end)
        {
            int mid = (start + end) / 2;
            int mid2 = mid*mid;
            
            if( mid2 == x )
                return mid;
            else if( mid2 < x )
                start = mid;
            else if( mid2 > x)
                end = mid;
        }
        
        int sqr = start*start;
        if(sqr == x)
            return start;
            
        sqr = end*end;
        if(sqr <= x)
            return end;
        
        return start;
        
    }
};
