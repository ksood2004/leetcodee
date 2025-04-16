class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=s.size();
        int m=g.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n && j<m){
            if(s[i]>=g[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};