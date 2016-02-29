class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());

        candies[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            } else {
                candies[i] = 1;
            }
        }
        
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }
        
        return sum;
    }
};