class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        
        // area = ( ia - ib ) * ( h[ia]-h[ib] );
        
        // // solution 1
        // for(i= 0 -> n)
        // {
        //     for( j = i -> n)
        //     {
        //         //calc area for set(i, j);
        //         max = max(max, tmp_area);
        //     }
        // }
        
        
        // two pointers point to start and the end of array
        
        if( heights.size() == 0 ) 
            return 0;
            
        int l = 0;
        int r = heights.size()-1;
        
        int max = -INT_MAX;
        while(l < r)
        {
            if(heights[l] < heights[r])
            {
                int area = heights[l] * (r-l);
                max = max > area ? max : area;
                l++;
            }
            else
            {
                int area = heights[r] * (r-l);
                max = max > area ? max : area;
                r--;
            }
        }
        
        return max;
    }
};