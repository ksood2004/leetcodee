class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;  // Left pointer of the sliding window
        int res = 0;  // Variable to store the result
        unordered_set<char> hello;  // Set to store characters in the current window
        
        for (int i = 0; i < s.size(); ++i) {
            // If the character at 'i' is already in the set, move the left pointer
            while (hello.find(s[i]) != hello.end()) {
                hello.erase(s[l]);  // Remove character at 'l' from the set
                l++;  // Move the left pointer to the right
            }
            // Add the current character to the set
            hello.insert(s[i]);
            // Update the result with the maximum length of the current window
            res = max(res, i - l + 1);
        }
        
        return res;
    }
};