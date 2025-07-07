class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=s.size();
        int m=g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s[i]>=g[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                i++;
            }

        }
        return cnt;
    }
};