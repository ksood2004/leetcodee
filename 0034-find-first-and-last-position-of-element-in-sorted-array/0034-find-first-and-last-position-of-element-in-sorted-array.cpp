class Solution {
public:
    int firstPosition(vector<int>& arr, int n, int k) {
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == k) {
                ans = mid;
                end = mid - 1;  
            } 
            else if (arr[mid] < k) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastPosition(vector<int>& arr, int n, int k) {
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == k) {
                ans = mid;
                start = mid + 1;  // Continue searching in the right half
            } 
            else if (arr[mid] < k) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstPosition(nums, n, target);
        int last = lastPosition(nums, n, target);
        return {first, last};
    }
};