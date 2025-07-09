class Solution {
public:
    int karan(string &s, string &tt) {
        int n = s.size();
        int k = tt.size();

        vector<vector<long long>> t(n + 1, vector<long long>(k + 1, 0));
        const int mod = 1e9 + 7;
        // Corrected initialization
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (s[i - 1] == tt[j - 1]) {
                    t[i][j] = (t[i - 1][j - 1] + t[i - 1][j])%mod;
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][k];
    }

    int numDistinct(string s, string t) {
        return karan(s, t);
    }
};
