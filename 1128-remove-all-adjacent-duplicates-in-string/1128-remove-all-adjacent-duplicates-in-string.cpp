// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string result;
//         for(int i=0;i<s.length();i++){
//             if(s[i]==s[i+1]){
//                 result.erase(s[i],s.length());
//             }
//             else{
//                 result.push_back(s[i]);
//             }
//         }
//         return result;
        
//     }
// };
class Solution {
public:
    string removeDuplicates(string s) {
        string result;  // This will act as a stack
        
        for (char ch : s) {
            if (!result.empty() && result.back() == ch) {
                // If the last character in 'result' is the same as the current character, remove it
                result.pop_back();
            } else {
                // Otherwise, add the current character to 'result'
                result.push_back(ch);
            }
        }
        
        return result;  // Return the final string after removing duplicates
    }
};
