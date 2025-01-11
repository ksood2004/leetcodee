class Solution {
public:
    int change(int sum, vector<int>& coins, int n) {
        int t[n + 1][sum + 1];
        
        // Initialize the DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) {
                    t[i][j] = INT_MAX - 1; // No coins, impossible to form any positive sum
                }
                if (j == 0) {
                    t[i][j] = 0; // Zero sum can always be formed with no coins
                }
            }
        }
        
        // Initialize the first row (when only the first coin is considered)
        for (int j = 1; j <= sum; j++) {
            if (j % coins[0] == 0) {
                t[1][j] = j / coins[0]; // Use as many of the first coin as needed
            } else {
                t[1][j] = INT_MAX - 1; // Impossible to form this sum
            }
        }
        
        // Fill the rest of the table
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i - 1] <= j) {
                    t[i][j] = min(t[i][j - coins[i - 1]] + 1, t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j]; // Exclude the coin
                }
            }
        }
        
        // If the amount cannot be formed, return -1
        return (t[n][sum] == INT_MAX - 1) ? -1 : t[n][sum];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        return change(amount, coins, n);
    }
};
