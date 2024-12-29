class Solution {
public:
void solve(int n, int k , int & ans,vector<int> person,int index){
    if(person.size()==1){
        ans=person[0];
        return;
    }
    index=(index+k)%person.size();
    person.erase(person.begin()+index);
    solve(n,k,ans,person,index);
}
    int findTheWinner(int n, int k) {
        int ans=-1;
        k=k-1;
        vector<int> karan;
        for(int i=0;i<n;i++){
            karan.push_back(i+1);
        }
        solve(n,k,ans,karan,0);
        return ans;
        
    }
};