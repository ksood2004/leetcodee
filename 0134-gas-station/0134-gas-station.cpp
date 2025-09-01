class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int togas=0;
        int tocost=0;
        int curr=0;
        int st=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            togas+=gas[i];
            tocost+=cost[i];

            curr+=gas[i]-cost[i];
            if(curr<0){
                st=i+1;
                curr=0;
            }
        }
        if(togas<tocost){
            return -1;
        }
        return st;
    }
};