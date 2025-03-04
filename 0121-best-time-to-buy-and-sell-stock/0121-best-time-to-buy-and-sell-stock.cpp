class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int price=0;
        int buy=prices[0];
        for(int i=1;i<n;i++){
            if(buy>prices[i]){
                buy=prices[i];
            }
            price=max(price,prices[i]-buy);
        }
        return price;
        
    }
};