class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,pair<int,int>>> karan;
        vector<int> prem;
        int n=points.size();
        for(int i=0;i<n;i++){
            karan.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}}); // jab 2 d array toh aise present krenge
            if(karan.size()>k){
                karan.pop();
            }

        }
         vector<vector<int>> result; // do vector list bcz ki humhe pair print krzznz hzi 
        while (!karan.empty()) {
           
            auto point = karan.top().second; // {x, y}
            karan.pop();
           
            result.push_back({point.first, point.second});
        }
        return result;
       
        
    
        
    }
};