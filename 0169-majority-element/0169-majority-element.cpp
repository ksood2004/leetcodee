class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> karan;
        int n=nums.size();
        for(int i=0;i<n;i++){
            karan[nums[i]]++;
        }
        int maxx=0;
        int ele=-1;
        for(auto& it: karan){
            int num=it.first;
            int freq=it.second;
         
            if(freq>maxx){
                maxx=freq;
                ele=num;
            }

        }
        if(maxx>n/2){
        return ele;
        }
        else{
            return -1;
        }
    }
};