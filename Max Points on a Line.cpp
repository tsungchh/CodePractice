/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        
        unordered_map<double, int> map;
        
        int max = 0;
        
        for(int i = 0; i < points.size(); i++)
        {
            map.clear();
            map[INT_MIN] = 1;
            int dup = 0;
            
            for(int j = i+1; j < points.size(); j++)
            {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;
                    continue;
                }
                
                if(points[j].x-points[i].x == 0)
                {
                    if(map.find(INT_MAX) == map.end())
                    {
                        map[INT_MAX] = 2;
                    }
                    else
                    {
                        map[INT_MAX]++;
                    }
                    continue;
                }
                
                double tangent = (double)(points[j].y - points[i].y) / (double)(points[j].x-points[i].x);
                
                if(map.find(tangent) == map.end())
                {
                    map[tangent] = 2;
                }
                else
                {
                    map[tangent]++;
                }
            }
            
            unordered_map<double, int>::iterator it = map.begin();
            for(; it!= map.end(); it++)
            {
                max = max > dup +it->second ? max : dup + it->second;
            }
        }
        
        
        return max;
        
    }
};
