class Solution {
public:
bool possible(vector<int>& arr,int days,int m,int k){
    int n=arr.size();
    int cnt=0;
    int bo=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=days){
            cnt++;
        }
        else{
            bo+=(cnt/k);
            cnt=0;
        }
    }
    bo+=(cnt/k);
    return bo>=m;
    
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        long long val = static_cast<long long>(m) * k;
        if(val>n){
            return -1;
        }
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int s=mini;
        int e=maxi;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(bloomDay,mid,m,k)){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
        
    }
};