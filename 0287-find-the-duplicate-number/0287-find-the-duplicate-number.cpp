class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        do {
            slow = nums[slow];          // Move one step
            fast = nums[nums[fast]];    // Move two steps
        } while (slow != fast);

        // Step 2: Find duplicate
        slow = nums[0];  // Reset slow to the start
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;  // Duplicate number
    }
};
