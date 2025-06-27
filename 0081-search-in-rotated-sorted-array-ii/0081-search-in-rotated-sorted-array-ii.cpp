class Solution {
public:
    int pivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[e]) {
                e = mid;
            } 
            else if (nums[mid] > nums[e]) {
                s = mid + 1;
            } 
            else {
                // nums[mid] == nums[e], can't decide the side, reduce e
                e--;
            }
        }
        return s;  // index of smallest element (pivot)
    }

    int bs(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = pivot(nums);

        if (target >= nums[p] && target <= nums[n - 1]) {
            return bs(nums, target, p, n - 1) != -1;
        } else {
            return bs(nums, target, 0, p - 1) != -1;
        }
    }
};
