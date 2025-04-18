class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> karan(n,1); // for left
        vector<int> aaryan(n,1); // for right;
        for(int i=1;i<n;i++){
            if (ratings[i] > ratings[i - 1]) {
                karan[i] = karan[i - 1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                aaryan[i]=aaryan[i+1]+1;
            }
        }
       int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(karan[i], aaryan[i]);
        }

        return sum;
    }
};