class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int step=n-1;
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(step<=i+nums[i]){
                step=i;
            }
        }
        return step==0;
    }
};