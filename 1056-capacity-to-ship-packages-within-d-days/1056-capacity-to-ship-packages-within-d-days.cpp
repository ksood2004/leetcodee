class Solution {
public:
int ship(vector<int>& nums,int cap){
    int n=nums.size();
    int load=0;
    int days=1;
    for(int i=0;i<n;i++){
        if(load+nums[i]>cap){
            days++;
            load=nums[i];
        }
        else{
            load+=nums[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int s=*max_element(weights.begin(),weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            int midn=ship(weights,mid);
            if(midn<=days){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};