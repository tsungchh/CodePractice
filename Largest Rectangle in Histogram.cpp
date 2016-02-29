class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        
        height.push_back(-1);
        stack<int> stk;
        stk.push(0);
        int max = 0;
        for(int i = 1; i < height.size(); i++)
        {
            while( !stk.empty() && height[stk.top()] > height[i] )
            {
                int h = height[stk.top()];
                stk.pop();
                int l = i - 1;
                int r = stk.empty() ? 0 : stk.top()+1;
                int w = l - r + 1; 
                max = w*h > max ? w*h : max;
            }
            stk.push(i);
        }
        
        return max;
    }
};