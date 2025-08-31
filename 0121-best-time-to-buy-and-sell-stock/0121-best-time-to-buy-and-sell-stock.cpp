class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=prices[0];
        int pro=0;
        for(int i=0;i<n;i++){
            if(maxi>prices[i]){
                maxi=prices[i];
            }
            pro=max(pro,prices[i]-maxi);
        }
        return pro;
    }
};