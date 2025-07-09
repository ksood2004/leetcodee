class Solution {
public:
int karann(vector<int>& nums){
    int n=nums.size();
    vector<int> karan=nums;
    sort(karan.begin(),karan.end());
    karan.erase(unique(karan.begin(), karan.end()), karan.end());
    int m=karan.size();
    vector<vector<int>> t(n+1,vector<int> (m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nums[i-1]==karan[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
    int lengthOfLIS(vector<int>& nums) {
        return karann(nums);
    }
};