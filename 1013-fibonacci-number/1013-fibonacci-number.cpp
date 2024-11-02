class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int num1=0;
        int temp;
        int num2=1;
        for(int i=2;i<=n;i++){
            temp=num2+num1;
            num1=num2;
            num2=temp;
        }

        return num2;
        
    }
};