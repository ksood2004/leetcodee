class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> karan;
        int n=nums.size();
        unordered_map<int,int> hi;
        for(int i=0;i<n;i++){
            hi[nums[i]]++;
        }
        for(auto& it: hi){
            if(it.second> n/3){
                karan.push_back(it.first);
            }
        }
        return karan;
    }
};