class Solution {
public:
int pivott(vector<int>& nums,int n){
   
        int s=0;
        int e=n-1;
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
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
        int pivottt=pivott(nums,n);
        
        // line wise code likhna hai for line 1
        if(target>=nums[pivottt] && target<=nums[n-1]){
            return bs(nums,target,pivottt,n-1);// bade elemnt wali line
        }
        else{
           return bs(nums,target,0,pivottt-1);

        }
        //return pivottt;
    }
};