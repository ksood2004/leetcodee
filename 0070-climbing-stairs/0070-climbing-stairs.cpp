class Solution {
public:
int t[46];
int karan(int n){
    t[0]=1;
    t[1]=1;
    for(int i=2;i<=n;i++){
       t[i]=t[i-1]+t[i-2];
    }
    return t[n];
}
    int climbStairs(int n) {
        
        memset(t,0,sizeof(t));
        return karan(n);
    }
};