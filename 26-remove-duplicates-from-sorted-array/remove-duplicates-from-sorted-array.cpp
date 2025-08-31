class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> karan;
        int n=nums.size();
        int index=0;
        for(int i=0;i<n;i++){
            karan.insert(nums[i]);
        }
        for(auto val:karan){
            nums[index]=val;
            index++;
        }
        return index;
    }
};