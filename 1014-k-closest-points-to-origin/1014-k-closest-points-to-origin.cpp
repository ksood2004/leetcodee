class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> karan;
        int n=points.size();
        priority_queue<int,pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push_back(points[i][0]*points[i][0]+points[i][1]*points[i][1],{point[i][0],points[i][1]});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            auto point=pq.top().second;
            pq.pop();
            karan.push_back(point);
        }
    }
};