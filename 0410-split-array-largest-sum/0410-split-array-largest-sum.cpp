class Solution {
public:
bool split(vector<int>& nums,int n,int maxsum,int k){
    int sum=0;
    int current=1;
    for(int i=0;i<n;i++){
        if(nums[i]>maxsum){
            return false;
        }
        else if(sum+nums[i]>maxsum){
            current++;
            sum=nums[i];
            if(current>k){
                return false;
            }
        }
        else{
            sum+=nums[i];
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int s=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int e=sum;
        int ans=-1;
        if(k>n){
            return -1;
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            if(split(nums,n,mid,k)){
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