class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    
    struct Point
    {
        int x, y, val;
        Point(int _x, int _y, int _val) : 
            x(_x),
            y(_y),
            val(_val)
        {
        }
        ~Point(){}
        
        Point& operator=(const Point p)
        {
            this->x = p.x;
            this->y = p.y;
            this->val = p.val;
            
            return *this;
        }
    };
    
    class myFunctor
    {
    public:
        myFunctor(){}
        ~myFunctor(){}
        
        bool operator()(const Point a, const Point b)
        {
            return a.val > b.val;
        }
    };
     
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        priority_queue<Point, vector<Point>, myFunctor> heap;
        for(int i = 0; i < matrix[0].size(); i++)
        {
            Point p(0, i, matrix[0][i]);
            heap.push(p);
        }
        
        int idx = 0;
        Point minPoint(-1, -1, -1);
        while(idx < k)
        {
            minPoint = heap.top();
            heap.pop();
            if(minPoint.x+1 < matrix.size())
            {
                Point pNext = Point(minPoint.x+1, minPoint.y, matrix[minPoint.x+1][minPoint.y]);
                heap.push(pNext);
            }
            idx++;
        }
        
        return minPoint.val;
        
    }
};