class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> karan={{0,0},{1,0},{2,0}};
        for(int i=0;i<n;i++){
            karan[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            int freq=karan[i];
            for(int j=0;j<freq;j++){
                nums[index]=i;
                index++;
            }
        }
        
    }
};