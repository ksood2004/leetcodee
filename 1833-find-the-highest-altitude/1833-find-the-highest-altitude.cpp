class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            curr=max(curr,sum);
        }
        return curr;
        
    }
};