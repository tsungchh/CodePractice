class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
            return 0;
        
        vector<int> profitL(prices.size(), 0);
        vector<int> profitR(prices.size(), 0);
        
        int profit = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            min = min < prices[i] ? min : prices[i];
            profit = (prices[i] - min) > profit ? prices[i] - min : profit;
            profitL[i] = profit;
        }
        
        int max = prices[prices.size()-1];
        profit = 0;
        for(int i = prices.size()-1; i >= 0; i--)
        {
            max = max > prices[i] ? max : prices[i];
            profit = (max - prices[i]) > profit ? (max - prices[i]) : profit;
            profitR[i] = profit;
        }
        
        profit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            profit = profit > profitL[i] + profitR[i] ? profit : profitL[i] + profitR[i];
        }
        
        return profit;
        
    }
    
};