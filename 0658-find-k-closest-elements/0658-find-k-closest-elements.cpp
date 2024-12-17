class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>> karan;
        vector<int> prem;
        int n=arr.size();
        for(int i=0;i<n;i++){
            karan.push({abs(arr[i]-x),arr[i]});
            if(karan.size()>k){
                karan.pop();
            }

        }
        while(karan.size()>0){
            prem.push_back(karan.top().second);
            karan.pop();
        }
        sort(prem.begin(),prem.end());
        return prem;
        
    }
};