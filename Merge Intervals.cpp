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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    class funcObj
    {
     public:
        bool operator()(const Interval& a, const Interval& b)
        {
            return a.start < b.start;
        }
    };
     
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        
        if(intervals.size() == 0)
            return vector<Interval>();
        
        funcObj func;
        sort(intervals.begin(), intervals.end(), func);
        
        vector<Interval> result;
        Interval last = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            Interval curt = intervals[i];
            if (curt.start <= last.end ){
                last.end = last.end > curt.end ? last.end : curt.end;
            }else{
                result.push_back(last);
                last = curt;
            }
        }
        
        result.push_back(last);
        return result;
    }
};
