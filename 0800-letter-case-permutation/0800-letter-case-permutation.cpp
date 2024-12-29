class Solution {
public:
    void solve(string ip, string op, vector<string>& result) {
        if (ip.length() == 0) {
            result.push_back(op);
            return;
        }
        // agar character hai toh
        if (isalpha(ip[0])) {
            
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));//lower character
            op2.push_back(toupper(ip[0])); // upper character
            ip.erase(ip.begin()+0);
            solve(ip, op1, result);
            solve(ip, op2, result);
        } else {
            // If the current character is not alphabetic, simply add it to output
            op.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip, op, result);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string op;
        solve(s, op, result);
        return result;
    }
};