class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
    int length=1;
        int karan=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])==1){
                length++;
            }
            else if(nums[i]-nums[i-1]==0){
                
            }
            else{
                length=1;
            }
            karan=max(karan,length);
        }
        return karan;
    }
};