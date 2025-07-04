class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int> karan(n+1);
        karan[0]=1;
        karan[1]=1;
        for(int i=2;i<=n;i++){
            karan[i]=karan[i-1]+karan[i-2];
            
        }
        return karan[n];
    }
};