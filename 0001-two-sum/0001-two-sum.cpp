class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> karan;
        for(int i=0;i<n;i++){
            int k=target-nums[i];
            if(karan.find(k) != karan.end()){
                return {karan[k],i};
            }
        karan[nums[i]]=i;
        }
        return {};
    }
};