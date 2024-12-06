class Solution {
    private:
    void subb(vector<int>output,vector<vector<int>> &ans,int index,vector<int>nums){
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }

        subb(output,ans,index+1,nums);
        int karan=nums[index];
        output.push_back(karan);
        subb(output,ans,index+1,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        subb(output,ans,index,nums);
        return ans;


        
    }
};