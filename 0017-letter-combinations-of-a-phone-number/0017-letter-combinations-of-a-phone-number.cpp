class Solution {
public:
void solve(string digits,vector<string>& ans,string mapping[],int index,string output){
    if(index==digits.size()){
        ans.push_back(output);
        return;
    }
    int num=digits[index]-'0';
    string karan=mapping[num];
    for(int i=0;i<karan.size();i++){
        output.push_back(karan[i]);
        solve(digits,ans,mapping,index+1,output);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};
        string hello;
        solve(digits,ans,mapping,0,hello);
        return ans;
        
    }
};