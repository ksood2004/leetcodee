class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> prem(n, -1);
        stack<int> karan;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!karan.empty() && karan.top() <= nums[i % n]) {
                karan.pop();
            }
            if (i < n) { 
                if (!karan.empty()) {
                    prem[i] = karan.top();
                }
            }
            karan.push(nums[i % n]);
        }
        return prem;
    }
};
