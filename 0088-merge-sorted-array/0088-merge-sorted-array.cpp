class Solution {
public:
    void swapp(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2) {
        if (nums1[idx1] > nums2[idx2]) {
            swap(nums1[idx1], nums2[idx2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n;
        int gap = (k / 2) + (k % 2);

        while (gap > 0) {
            int i = 0;
            int j = i + gap;

            while (j < k) {
                // arr1 and arr1
                if (i < m && j < m) {
                    swapp(nums1, nums1, i, j);
                }
                // arr1 and arr2
                else if (i < m && j >= m) {
                    swapp(nums1, nums2, i, j - m);
                }
                // arr2 and arr2
                else {
                    swapp(nums2, nums2, i - m, j - m);
                }

                i++;
                j++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }

        // Copy sorted nums2 back into nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};
