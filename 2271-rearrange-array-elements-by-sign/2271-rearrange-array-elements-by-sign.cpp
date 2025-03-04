class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans,pos,neg;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        int i=0;
        int j=0;
        while(i<neg.size()){
            ans.push_back(pos[i]);
            i++;
            ans.push_back(neg[j]);
            j++;
        }
        return ans;
        
    }
};