class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end()),res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            long long th=0;
            for(int p:piles){
                th += ceil((double) p/mid);
            }
            if(th<=h){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
                }
        }
        return res;        
    }
};