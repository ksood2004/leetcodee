class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSum; // Map to store cumulative sum and its frequency
        prefixSum[0] = 1; // Initialize with 0 sum to handle subarrays starting from index 0

        for (int num : nums) {
            sum += num; // Compute the cumulative sum
            
            // Check if `sum - k` exists in the map
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k]; // Increment count by the frequency of `sum - k`
            }

            // Update the map with the current sum
            prefixSum[sum]++;
        }

        return count;
    }
};