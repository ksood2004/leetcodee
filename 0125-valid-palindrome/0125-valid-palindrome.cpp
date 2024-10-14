class Solution {
public:
bool isAlphanumeric(char ch) {
    return (ch>='A' && ch<='Z')||(ch>='a'&&ch<='z') || (ch >= '0' && ch <= '9');
}
    bool isPalindrome(string s) {
        int start = 0;
    int end = s.size() - 1;

    while (start < end) {
        // Ignore non-alphanumeric characters
        while (start < end && !isAlphanumeric(s[start])) {
            start++;
        }
        while (start < end && !isAlphanumeric(s[end])) {
            end--;
        }

        // Compare the characters after converting to lowercase
        if (tolower(s[start]) != tolower(s[end])) {
            return false;  // Not a palindrome
        }
        start++;
        end--;
    }
    return true;  
        
    }
};