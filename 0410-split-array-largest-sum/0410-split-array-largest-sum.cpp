class Solution {
public:
bool karan(vector<int>& nums,int n,int k,int maxsum){
    int current=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>maxsum){
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
        int sum=0;
        int maxx=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxx=max(maxx,nums[i]);
        }
        int s=maxx;
        int e=sum;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(karan(nums,n,k,mid)){
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