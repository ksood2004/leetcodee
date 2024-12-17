class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>karan;
        for(int i=0;i<n;i++){
            karan.push(nums[i]);
            if(karan.size()>k){
                karan.pop();
            }

        }
        return karan.top();

        
    }
};