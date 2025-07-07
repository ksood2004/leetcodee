class Solution {
public:
    int hello(vector<int>& coins, int sum, int n) {
        // Use long long to prevent overflow
        unsigned long long t[n + 1][sum + 1];

        // Initialize the DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j == 0) {
                    t[i][j] = 1; // One way to make sum 0 (no coins)
                } else if (i == 0) {
                    t[i][j] = 0; // Zero ways to make positive sum with 0 coins
                }
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i - 1] <= j) {
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j]; // include + exclude
                } else {
                    t[i][j] = t[i - 1][j]; // exclude only
                }
            }
        }

        return t[n][sum];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return hello(coins, amount, n);
    }
};
