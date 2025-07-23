#include <vector>
#include <algorithm> // For std::min and std::max

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();

        // Edge case: Need at least 2 days to make a transaction.
        if (n < 2) {
            return 0;
        }
        std::vector<int> profit1(n, 0);
        int min_price = prices[0]; // Track the minimum price seen so far from the left
        for (int i = 1; i < n; ++i) {
            min_price = std::min(min_price, prices[i]);
            profit1[i] = std::max(profit1[i-1], prices[i] - min_price);
        }
        std::vector<int> profit2(n, 0);
        int max_price = prices[n-1]; 
        for (int i = n - 2; i >= 0; --i) {
            max_price = std::max(max_price, prices[i]);
            profit2[i] = std::max(profit2[i+1], max_price - prices[i]);
        }

        int total_max_profit = 0;
        for (int i = 0; i < n; ++i) {
            total_max_profit = std::max(total_max_profit, profit1[i] + profit2[i]);
        }
        
       
        
        return total_max_profit;
    }
};