class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> karan;

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        karan.push_back(nums[0]);  // include the first element

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                karan.push_back(nums[i]);
            }
        }

        // Copy back to original vector (if needed)
        for (int i = 0; i < karan.size(); i++) {
            nums[i] = karan[i];
        }

        return karan.size();
    }
};
