class Solution {
public:
    int countSubsetSums(vector<int>& arr, int n, int target) {
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  
        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] += dp[j - num];  
            }
        }
        
        return dp[target];  
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        
        for (int num : nums) {
            sum += num;
        }
        
        if ((sum + target) % 2 != 0) {
            return 0;
        }
        
        int d = (sum + target) / 2;

        
        if (d < 0 || d > sum) {
            return 0;
        }

        return countSubsetSums(nums, n, d);
    }
};
