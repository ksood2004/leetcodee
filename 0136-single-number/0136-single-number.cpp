class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> karan;
        for(int i=0;i<nums.size();i++){
            karan[nums[i]]++;
        }
        vector<int> hello;
        for(auto it: karan){
            int key=it.first;
            int value=it.second;
            if(value==1){
                return key;
            }
        }
        return -1;
        
    }
};