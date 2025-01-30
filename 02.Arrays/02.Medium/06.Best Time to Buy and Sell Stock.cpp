class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // greddy approach
        // intitialize buy price , max profit , currprice
        // iterate over the prices
        // if the currprice - buyprice >  profit then update profit
        // if the buy price < currprice , update currprice with buyprice

        // 1
        int buy_price = prices[0];
        int max_profit = 0;
        int curr_price = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            // max profit check
            curr_price = prices[i];
            if (curr_price - buy_price > max_profit) {
                max_profit = curr_price - buy_price;
            }

            // buyprice update check
            if (buy_price > curr_price) {
                buy_price = curr_price;
            }

        }
        return max_profit;
    }
};