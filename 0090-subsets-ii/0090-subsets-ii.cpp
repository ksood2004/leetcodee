class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int>& ip,vector<int> & op,int index){
    ans.push_back(op);
    
    for(int i=index;i<ip.size();i++){
        if(i >index && ip[i]==ip[i-1]){
            continue; 
        }
         op.push_back(ip[i]);

        solve(ip, op, i + 1);

        op.pop_back();
    }

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> karan;
        sort(nums.begin(),nums.end());
        solve(nums,karan,0);
        return ans;
}
};