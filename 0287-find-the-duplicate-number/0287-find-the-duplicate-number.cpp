class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;  
            if (mpp[num] > 1) {
                return num;  
            }
        }
        
        return -1; 
    }
};