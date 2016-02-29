/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        
        if(airplanes.size() == 0 )
            return 0;
        
        int min = INT_MAX;
        int max = 0;
        
        for(int i = 0; i < airplanes.size(); i++)
        {
            min = min < airplanes[i].start ? min : airplanes[i].start;
            max = max > airplanes[i].end ? max : airplanes[i].end;
        }
        
        vector<int> ary(max-min+1, 0);
        
        for(int i = 0; i < airplanes.size(); i++)
        {
            int startIdx = airplanes[i].start - min;
            int endIdx = airplanes[i].end - min - 1;
            if(startIdx > endIdx)
                continue;
            for(int j = startIdx; j <= endIdx; j++)
            {
                ary[j]++;
            }
        }
        
        int ret = 0;
        for(int i = 0; i < ary.size(); i++)
        {
            ret = ret > ary[i] ? ret : ary[i];
        }
        
        return ret;
        
    }
};


