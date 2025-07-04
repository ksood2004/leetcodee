class Solution {
public:
bool t[1001][40001];
bool karan(vector<int>& nums,int sum,int n){
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

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1]<=j){
                t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
    bool canPartition(vector<int>& nums) {
        memset(t,0,sizeof(t));
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        return karan(nums,sum/2,n);
    }
};