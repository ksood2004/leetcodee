class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        map<int,int> karan;
        for(int i=0;i<n;i++){
            karan[nums[i]]++;
        }
        int index=0;
        for(auto& it: karan){
            int val=it.first;
            int freq=min(it.second,2);
            for(int i=0;i<freq;i++){
                nums[index]=val;
                index++;
            }
            
        }
        return index;
    }
};