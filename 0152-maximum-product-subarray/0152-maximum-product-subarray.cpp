class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int a=1;
        int k=1;
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            if(a==0){
                a=1;
            } // jab hum kar rhe approch from 0 to k
            if(k==0){
                k=1;
            }// jab k to n
            a=a*nums[i];
            k=k*nums[n-i-1];
            maxx=max(maxx,max(k,a));
        }
        return maxx;
        
    }
};