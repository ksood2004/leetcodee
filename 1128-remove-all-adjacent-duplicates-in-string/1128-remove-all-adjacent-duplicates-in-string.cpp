class Solution {
public:
    string removeDuplicates(string s) {
        int j = 0;  // `j` keeps track of the end of the valid portion of the string

        for (int i = 0; i < s.length(); i++) {
            if (j > 0 && s[j - 1] == s[i]) {
                // If the last valid character (s[j-1]) is the same as the current one, remove it
                j--;  // Effectively "removes" the previous character
            } else {
                // Otherwise, move the current character to the valid portion of the string
                s[j] = s[i];
                j++;
            }
        }
        
        // Resize the string to the valid length
        s.resize(j);
        return s;
    }
};
