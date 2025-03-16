class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans=-1;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int key=it->first;
            int value=it->second;
            if(value==1){
                ans=key;
            }
        }
    return ans;    
    }
};