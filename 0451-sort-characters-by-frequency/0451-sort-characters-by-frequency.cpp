class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> myMap;
        for (char num : s) {
            myMap[num]++;
        }
        priority_queue<pair<int,int>> karan;
 
       
        for (auto it = myMap.begin(); it != myMap.end(); ++it){
            karan.push({it->second,it->first});
        }
        s="";
        while(!karan.empty()){
            s+=string(karan.top().first,karan.top().second);
            karan.pop();
        }
     
       return s; 
    }
        
    
};
        
