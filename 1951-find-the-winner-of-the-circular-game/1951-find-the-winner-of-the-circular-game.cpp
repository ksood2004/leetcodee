class Solution {
public:
// void solve(int n, int k , int & ans,vector<int> person,int index){
//     if(person.size()==1){
//         ans=person[0];
//         return;
//     }
//     index=(index+k)%person.size();
//     person.erase(person.begin()+index);
//     solve(n,k,ans,person,index);
// }
    int findTheWinner(int n, int k) {
        queue<int> karan;
        for(int i=1;i<=n;i++){
        karan.push(i);
        }
        while(karan.size()>1){
            for(int i=1;i<k;i++){
                karan.push(karan.front());
                karan.pop();
            }
            karan.pop();
        }
        return karan.front();
        
    }
};