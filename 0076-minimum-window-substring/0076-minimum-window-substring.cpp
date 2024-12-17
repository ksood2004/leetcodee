class Solution {
public:
    
string minWindow(string s, string t) {
        unordered_map<char, int> mp; // To store frequency of characters in t
        for (char ch : t) mp[ch]++;  // Populate the map with t's characters

        int i = 0, j = 0;            // Two pointers for the sliding window
        int minLen = INT_MAX, start = 0; // To store the minimum length and start of the result
        int count = t.size();        // Total characters we need to match

        while (j < s.size()) {
            // Decrease count if s[j] is part of t and needed
            if (mp[s[j]] > 0) count--;
            mp[s[j]]--;  // Reduce the frequency of current character
            j++;

            // When all characters are matched
            while (count == 0) {
                // Update minimum window length
                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;
                }
                // Move the left pointer to minimize the window
                mp[s[i]]++;
                if (mp[s[i]] > 0) count++;
                i++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }

};