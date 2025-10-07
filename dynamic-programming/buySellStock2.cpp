// Best Time to Buy and Sell Stock II
// given an integer array prices, the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
// However, you can sell and buy the stock multiple times on the same day, ensuring you never hold than one share of the stock.
// Find and return the maximum profit that can be achieved.

class Solution {
    int n;
    int t[30001][2];

private:
    int solve(int idx, bool canBuy, vector<int>& prices){
        if(idx == n) return 0;

        if(t[idx][canBuy] != -1) return t[idx][canBuy];

        if(canBuy) {
            // buy 
            int buy = -prices[idx] + solve(idx + 1, 0, prices);
            
            // don't buy
            int skip = solve(idx+1, 1, prices);

            return t[idx][canBuy] = max(buy, skip);
        }
        else {
            // sell
            int sell = prices[idx] + solve(idx + 1, 1, prices);

            // don't sell
            int skip = solve(idx + 1, 0, prices);

            return t[idx][canBuy] = max(sell, skip);
        }
    }


public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t, -1, sizeof(t));

        return solve(0, true, prices);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)