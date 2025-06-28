class Solution {
public:
int smallest(vector<int>& nums, int k){
   
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
    sum+=ceil(double(nums[i])/k);
        
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(smallest(nums,mid)<=threshold){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};