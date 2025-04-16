class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());  // Sort coins in ascending order

        int sum = 0;       // Current reachable sum
        int count = 0;     // Coins we need to add
        int i = 0;         // Index for original coins

        while (sum < target) {
            if (i < coins.size() && coins[i] <= sum + 1) {
                sum += coins[i];  // Use this coin
                i++;
            } else {
                // Add a new coin of value sum+1
                sum += sum + 1;
                count++;
            }
        }

        return count;
    }
};
    