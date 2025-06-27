class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long sq = 1LL * mid * mid;

            if (sq == x) {
                return mid;
            } else if (sq < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
