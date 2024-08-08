//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//121. Best Time to Buy and Sell Stock.cpp
// TC - O(n), SC - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy_stock = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - buy_stock);

            buy_stock = min(buy_stock, prices[i]);
        }
        return profit;
    }
};
