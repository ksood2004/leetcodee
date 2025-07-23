class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int n=prices.size();
        int min_price=prices[0];
        for(int i=1;i<n;i++){
            if(min_price>prices[i]){
                min_price=prices[i];
            }
            mx=max(mx,prices[i]-min_price);
        }
        return mx;
    }
};