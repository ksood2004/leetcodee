#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        // Merging both arrays
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());

        // Sorting merged array
        sort(merged.begin(), merged.end());

        int size = merged.size();
        if (size % 2 == 0) {
            return (merged[size / 2] + merged[(size / 2) - 1]) / 2.0; // Corrected median calculation
        } else {
            return merged[size / 2];
        }
    }
};

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<int> nums1(n), nums2(m);

//     for (int i = 0; i < n; i++) {
//         cin >> nums1[i];
//     }
//     for (int i = 0; i < m; i++) {
//         cin >> nums2[i];
//     }

//     Solution solution;
//     cout << fixed << setprecision(5) << solution.findMedianSortedArrays(nums1, nums2) << endl;

//     return 0;
// }