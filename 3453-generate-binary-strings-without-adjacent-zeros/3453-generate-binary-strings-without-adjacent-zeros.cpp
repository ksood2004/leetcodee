class Solution {
public:
 void f(int n, string op, vector<string> &ans) {
        if (op.size() == n) {
            ans.push_back(op);
            return;
        }

        // Always add '0'
        f(n, op + '1', ans);

        // Add '1' only if the last character is not '1'
        if (op.empty() || op.back() != '0') {
            f(n, op + '0', ans);
        }
 }
    vector<string> validStrings(int n) {
         vector<string> ans;
        f(n, "", ans);
        return ans;
    }
};