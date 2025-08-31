class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> karan;
        int n=nums.size();
        for(int i=0;i<n;i++){
            karan[nums[i]]++;
        }
        int mx=-1;
        int ans=0;
        for(auto& it:karan){
            int num=it.first;
            int freq=it.second;
            if(freq>mx){
                mx=freq;
                ans=num;
            }
            
        }
        return ans;
    }
};