class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int bestbuy=prices[0];
        // int profit=0;

        // for(int i=1; i<prices.size(); i++) {

        //     if(prices[i] > bestbuy) {
        //         profit=max(profit,prices[i]-bestbuy);
        //     }
        //     bestbuy=min(bestbuy,prices[i]);
        // }
        // return profit;

        int bestbuy = prices[0];
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++) {

            int currProfit = prices[i] - bestbuy;
            maxProfit = max(maxProfit, currProfit);
            
            if(prices[i] < bestbuy) {
                bestbuy = prices[i];
            }
        }
        return maxProfit;
    }
};