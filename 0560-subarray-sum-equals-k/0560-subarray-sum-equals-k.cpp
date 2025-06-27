class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> karan;
        karan[0]=1;
        int sum=0;
        int cnt=0;
        for(int num: nums){
            sum+=num;
            if(karan.find(sum-k)!=karan.end()){
                
                cnt+=karan[sum-k];
            }
            karan[sum]++;
        }
        return cnt;
    }
};