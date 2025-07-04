class Solution {
public:
    int karn(vector<int>& karan) {
        int n = karan.size();
        if (n == 0) return 0;
        if (n == 1) return karan[0];

        vector<int> t(n);
        t[0] = karan[0];
        t[1] = max(karan[0], karan[1]);

        for (int i = 2; i < n; i++) {
            t[i] = max(t[i - 1], t[i - 2] + karan[i]);
        }
        return t[n - 1];
    }

    int rob(vector<int>& nums) {
        return karn(nums);
    }
};
