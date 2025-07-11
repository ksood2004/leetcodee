class Solution {
public:
    int karan(int m, int n) {
        int t[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }

        t[1][1] = 1; 

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) continue; 
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }

        return t[m][n];
    }

    int uniquePaths(int m, int n) {
        return karan(m, n);
    }
};
