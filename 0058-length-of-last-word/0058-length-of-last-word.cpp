class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int si=0;
        int i=n-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            si++;
            i--;
        }
        return si;
    }
};