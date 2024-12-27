class Solution {
public:
void solve(vector<int>& ip, vector<int>& op,vector<vector<int>>& opp){
    if(ip.size()==0){
        opp.push_back(op);
        return;
    }
    vector<int> op1=op;
    vector<int> op2=op;
    op2.push_back(ip[0]);
    vector<int>erasee(ip.begin()+1,ip.end());
    solve(erasee,op1,opp);
    solve(erasee,op2,opp);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result; // To store all subsets
        vector<int> op; // To store the current subset
        solve(nums, op, result);
        return result;
        
    }
};