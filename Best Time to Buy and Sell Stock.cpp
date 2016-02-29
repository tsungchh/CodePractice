class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        
        if(prices.size() == 0)
            return 0;
        
        int diffMax = 0;
        int min = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min)
            {
                min = prices[i];
                continue;
            }
            diffMax = diffMax > prices[i]-min ? diffMax : prices[i]-min;
        }
        
        return diffMax;
    }
};

