class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int maxx=1;
        int ans=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])==1){
                maxx++;
            }
            else if(nums[i]-nums[i-1]==0){

            }
            else{
                maxx=1;
            }
           ans=max(ans,maxx); 

        }
        return ans;
    }
};