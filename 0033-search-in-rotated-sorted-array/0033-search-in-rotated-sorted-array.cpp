class Solution {
public:
int pivott(vector<int>&nums){
    int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
}

int bs(vector<int>& nums, int target,int s,int e){
    int n=nums.size();
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            
        }
        return -1;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int nn=pivott(nums);
//chote integers ke liye
        if(target>=nums[nn] && target<=nums[n-1]){
            return bs(nums,target,nn,n-1);
        }
        else{
            return bs(nums,target,0,nn-1);
        }
    }
};