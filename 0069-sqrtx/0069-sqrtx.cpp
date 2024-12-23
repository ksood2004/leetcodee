class Solution {
public:
    int mySqrt(int x) {
      long long int start=0;
        long long int end=x;
        long long int ans=-1;
        while(start<=end){
            long long int mid=start+(end-start)/2;
            long long int k=mid*mid;;
            if(k==x){
                return mid;
            }
            else if(k>x){
                end=mid-1;
            }
            else{
                ans=mid;
                start=mid+1;

            }
            mid=start+(end-start)/2;
        }
        return ans;
        

    }
};