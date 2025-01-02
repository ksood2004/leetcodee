class Solution {
public:
    unordered_set<string> prem;
    unordered_map<int, bool> memo;

    bool solve(int index, string &s) {
        if (index == s.size()) { // Base case: reached the end of the string
            return true;
        }

        if (memo.find(index) != memo.end()) { // Check if result for this index is already computed
            return memo[index];
        }

        string temp = "";
        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (prem.find(temp) != prem.end()) { // Check if substring is in the dictionary
                if (solve(i + 1, s)) { // Recursive call to check the rest of the string
                    return memo[index] = true; // Cache the result and return true
                }
            }
        }
        return memo[index] = false; // Cache the result and return false
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Populate the set with dictionary words
        for (const string &word : wordDict) {
            prem.insert(word);
        }

        return solve(0, s); // Start solving from index 0
    }
};
