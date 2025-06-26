class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        int n=arr.size();
        vector<int> karan;
        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            karan.push_back(pq.top().second);
            pq.pop();
        }
        sort(karan.begin(),karan.end());
        return karan;
    }
};
 