class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=INT_MIN;
        int pur=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<pur){
                pur=prices[i];
            }
            profit=max(profit,prices[i]-pur);
            
        }
    return profit;    
    }
};