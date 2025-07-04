class Solution {
public:
void sub( vector<int>& ip,vector<int>& op,vector<vector<int>>& karan){
    if(ip.size()==0){
        karan.push_back(op);
        return ;
    }
    vector<int> op1=op;
    vector<int> op2=op;
    op1.push_back(ip[0]);
    vector<int>erase(ip.begin()+1,ip.end());
    sub(erase,op1,karan);
    sub(erase,op2,karan);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> karan;
        vector<int> op;
        sub(nums,op,karan);
        return karan;
    }
};