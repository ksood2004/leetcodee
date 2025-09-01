class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
        vector<int> karan(n,1);

        int ans=1;
        for(int i=0;i<n;i++){
            karan[i]=ans;
            ans*=nums[i];
        }

        ans=1;
        for(int i=n-1;i>=0;i--){
            karan[i]*=ans;
            ans*=nums[i];
        }
        return karan;
    }
};