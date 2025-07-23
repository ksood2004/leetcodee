class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=INT_MIN;
        int mx=0;
        for(int i=0;i<prices.size();i++){
            buy=max(buy,mx-prices[i]);
            mx=max(mx,prices[i]+buy-fee);
        }
        return mx;
    }
};