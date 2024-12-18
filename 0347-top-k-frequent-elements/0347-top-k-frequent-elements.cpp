class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (int num : nums) {
            myMap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,    greater<pair<int, int>>> karan;
 
        vector<int> prem;
        int n=nums.size();
        for (auto it = myMap.begin(); it != myMap.end(); ++it){
            karan.push({it->second,it->first});
            if(karan.size()>k){
                karan.pop();
            }

        }
        while(!karan.empty()){
            prem.push_back(karan.top().second);
            karan.pop();
        }
        
        return prem;
        
    }
        
    
};