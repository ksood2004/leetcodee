class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int t[n + 1][m + 1];
        
        // Fill the LCS DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                } else if (str1[i - 1] == str2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        string result = "";
        
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result = str1[i - 1] + result;
                i--;
                j--;
            } else if (t[i - 1][j] > t[i][j - 1]) {
                result = str1[i - 1] + result;
                i--;
            } else {
                result = str2[j - 1] + result;
                j--;
            }
        }

        while (i > 0) {
            result = str1[i - 1] + result;
            i--;
        }
        while (j > 0) {
            result = str2[j - 1] + result;
            j--;
        }
        
        return result;
    }
};
