class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyRate = INT_MAX;
        int MaxProfit = 0;
        for (int index = 0; index < prices.size(); index++) {
            if (buyRate > prices[index])
                buyRate = prices[index];
            else
                MaxProfit = max((prices[index] - buyRate), MaxProfit);
        }
        return MaxProfit;
    }
};