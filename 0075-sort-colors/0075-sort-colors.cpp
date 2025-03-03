class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> karan={{0,0},{1,0},{2,0}};
        for(int num: nums){
            karan[num]++;
        }
        int n=nums.size();
        int idx=0;
        for(int i=0;i<3;i++){
            int freq=karan[i];
            for(int j=0;j<freq;j++){
                nums[idx]=i;
                idx++;
            }
        }
    }
};