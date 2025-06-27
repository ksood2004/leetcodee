class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int> karan;
        int n=nums.size();
        for(int i=0;i<n;i++){
            karan[nums[i]]++;
        }
        int index=-1;
        for(auto& it:karan){
            int num=it.first;
            int freq=it.second;
            if(freq==1){
                index=num;
            }
        }
      return index;  
    }
};