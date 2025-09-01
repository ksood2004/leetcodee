class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int mx=0;
        sort(citations.begin(),citations.end());
        for(int i=0;i<n;i++){
            int paper=n-i;
            mx=max(mx,min(paper,citations[i]));
        }
        return mx;
    }
};