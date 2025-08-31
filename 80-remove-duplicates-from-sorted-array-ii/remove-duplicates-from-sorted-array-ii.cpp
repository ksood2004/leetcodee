class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        map<int,int> karan;
        int index=0;
        for(int i=0;i<n;i++){
            karan[nums[i]]++;
            if(karan[nums[i]]<=2){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};