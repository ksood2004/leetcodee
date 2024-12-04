class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==0){
            return x;
        }
        if (n < 0) { 
            x = 1 / x;// jo bhi power minus wali hai woh likhni hai
            if (n == INT_MIN) { 
                n = INT_MAX;
                x *= x; // Multiply once because we are losing 1 in converting to positive
            } else {
                n = -n; //jo negative value hai ussey possitve mein convert kiya 
            }
        }
        double poww=myPow(x,n/2);
        if(n%2==0){
            return poww*poww;
        }
        else{
            return x*poww*poww;
        }
        
    }
};