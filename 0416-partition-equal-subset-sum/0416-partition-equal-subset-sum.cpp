class Solution {
public:
bool t[201][40001];
  bool karan(int n,int sum,vector<int>& arr){
      for(int i=0;i<=n;i++){
          for(int j=0;j<=sum;j++){
              if(i==0){
              t[i][j]=false;
          }
          if(j==0){
              t[i][j]=true;
          }
        }
    }
          
          for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            } 
            else {
                t[i][j] = t[i - 1][j];
            }
        }
   }
  

    return t[n][sum];
}

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int summ = 0;

        for (int i = 0; i < n; i++) {
            summ += nums[i];
        }

        if (summ % 2 != 0) {
            return false;
        }

        return karan(n, summ / 2, nums);
    }
};