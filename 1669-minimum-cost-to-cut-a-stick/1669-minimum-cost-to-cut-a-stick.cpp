class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the two ends (0 and n) and sort the cuts
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));

        // len is the length of the segment we are solving
        for (int len = 2; len < c; ++len) {
            for (int i = 0; i + len < c; ++i) {
                int j = i + len;
                int cost = INT_MAX;

                // Try all cuts between i and j
                for (int k = i + 1; k < j; ++k) {
                    cost = min(cost, dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }

                dp[i][j] = cost;
            }
        }

        return dp[0][c - 1];
    }
};
