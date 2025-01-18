class Solution {
public:
    int t[101][10001]; // Memoization table

    int solve(int k, int n) {
        // Base cases
        if (n == 0 || n == 1) {
            return n; // 0 attempts for 0 floors, 1 attempt for 1 floor
        }
        if (k == 1) {
            return n; // If only 1 egg, try all floors linearly
        }

        // Check if the result is already calculated
        if (t[k][n] != -1) {
            return t[k][n];
        }

        int low = 1, high = n, minn = INT_MAX;

        // Binary search to find the optimal floor
        while (low <= high) {
            int mid = (low + high) / 2;

            int eggBreaks = solve(k - 1, mid - 1);  // Egg breaks
            int eggDoesNotBreak = solve(k, n - mid); // Egg does not break

            int temp = 1 + max(eggBreaks, eggDoesNotBreak); // Worst-case attempts
            minn = min(minn, temp); // Minimize the worst-case attempts

            // Adjust the binary search range
            if (eggBreaks > eggDoesNotBreak) {
                high = mid - 1; // Focus on lower floors
            } else {
                low = mid + 1; // Focus on upper floors
            }
        }

        // Store the result in the memoization table
        return t[k][n] = minn;
    }

    int superEggDrop(int k, int n) {
        memset(t, -1, sizeof(t)); // Initialize memoization table with -1
        return solve(k, n);
    }
};
