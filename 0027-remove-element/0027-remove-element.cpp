class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int karan=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[karan++]=nums[i];
            }

        }
        return karan;
        
    }
};