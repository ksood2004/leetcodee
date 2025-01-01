class Solution {
public:
bool ispalin(string &s,int i,int j){
    if(i>=j){// ek character hi hai 
    return true;
    }
    if(s[i]!= s[j]){
        return false;
        }
    return ispalin(s,i+1,j-1);
}

void solve(vector<vector<string>>& karan,vector<string>& prem,string & s, int index){
    if(index==s.size()){
        karan.push_back(prem);
        return;
    }
    string hello="" ;
    for(int i=index;i<s.size();i++){
        hello+=s[i];
        if(ispalin(s,index,i)){
            prem.push_back(hello);
            solve(karan,prem,s,i+1);
            prem.pop_back(); // backtracking karne ke liye humne yeh use kiya hai 
        }
    }
    return;
}

    vector<vector<string>> partition(string s) {
       vector<vector<string>> karan;
        vector<string> prem;
        solve(karan,prem,s,0);
        return karan;
        
    }
};