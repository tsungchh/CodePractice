class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        // backtracking
        vector<int> ans;
        helper(0, 0, n, ans);
        return ans;
    }
    
    void helper(int val, int currIdx, int n, vector<int>& ans)
    {
        if(currIdx == n)
        {
            if(val > 0) 
                ans.push_back(val);
            return;
        }
        
        val *= 10;
        for(int i = 0; i <= 9; i++)
        {
            int newVal = val + i;
            helper(newVal, currIdx+1, n, ans);
        }
        
    }
};