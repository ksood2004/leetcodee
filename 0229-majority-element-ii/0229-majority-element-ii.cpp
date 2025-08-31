class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> karan;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;
        int mx=-1;
        for(auto& it : mp){
            int val=it.first;
            int freq=it.second;
            if(freq>n/3){
              
                karan.push_back(val);
            }
        }
        return karan;
    }
};