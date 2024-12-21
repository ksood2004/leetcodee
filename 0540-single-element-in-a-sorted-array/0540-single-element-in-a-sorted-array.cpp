class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> karan;
        for(int i=0;i<nums.size();i++){
            karan[nums[i]]++;
        }
        int prem=-1;;

        for(auto it=karan.begin();it!=karan.end();it++){
            int key=it->first;
            int value=it->second;
            if(value==1){
                prem=key;

            }
        }
        return prem;
        
    }
};