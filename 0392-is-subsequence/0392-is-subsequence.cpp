class Solution {
public:

bool karan(string &s,string &c,int n,int m){
    //bool t[n+1][m+1];
   
    bool t[n+1][m+1];
    for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    t[i][j] = true;
                } else if (j == 0) {
                    t[i][j] = false; // Non-empty `s` can't be a subsequence of an empty `t`
                } else if (s[i - 1] == c[j - 1]) {
                    t[i][j] = t[i - 1][j - 1]; // Match found, move diagonally
                } else {
                    t[i][j] = t[i][j - 1]; // Skip current character of `t`
                }
            }
        }

    
    return t[n][m];

}
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        return karan(s,t,n,m);
    }
};