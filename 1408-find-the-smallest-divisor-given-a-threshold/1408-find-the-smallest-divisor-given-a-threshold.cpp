class Solution {
public:
     int small(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += ceil(double(nums[i]) / k);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1; // Start from 1, not 0 (avoid division by zero)
        int e = *max_element(nums.begin(), nums.end());
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int midn = small(nums, mid); // Correct function call

            if (midn > threshold) {
                s = mid + 1; 
            } else {
                ans = mid; 
                e = mid - 1;
            }
        }
        return ans;
    }
};