class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        
        // bool down = true;
        
        // int profit = 0;
        // int upStart = 0;
        
        // for(int i = 1; i < prices.size(); i++)
        // {
        //     if(prices[i] - prices[i-1] > 0)
        //     {
        //         if(down)
        //         {
        //             upStart = i-1;
        //             down = false;
        //         }
                
        //     }
        //     else
        //     {
        //         if(!down)
        //         {
        //             profit += (prices[i-1] - prices[upStart]);
        //             down = true;
        //         }
        //     }
        // }
        
        // if(!down)
        //     profit += (prices[prices.size()-1] - prices[upStart]);
        
        // return profit;
        
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                profit += (prices[i]- prices[i-1]);
        }
        
        return profit;
        
    }
};
