class Solution {
public:
    void mergesort(vector<int>& arr, int s, int e, int& reversePairsCount) {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        int* arr1 = new int[len1];
        int* arr2 = new int[len2];

        int index = s;
        for (int i = 0; i < len1; i++) {
            arr1[i] = arr[index++];
        }

        index = mid + 1;
        for (int i = 0; i < len2; i++) {
            arr2[i] = arr[index++];
        }

        // **Count reverse pairs:**
        int countIndex = mid + 1;
        for (int i = s; i <= mid; i++) {
            while (countIndex <= e && (long long)arr[i] > 2LL * arr[countIndex]) {
                countIndex++;
            }
            reversePairsCount += countIndex - (mid + 1);
        }

        // Merge two sorted halves
        int ind1 = 0, ind2 = 0;
        index = s;
        while (ind1 < len1 && ind2 < len2) {
            if (arr1[ind1] <= arr2[ind2]) {
                arr[index++] = arr1[ind1++];
            } else {
                arr[index++] = arr2[ind2++];
            }
        }

        while (ind1 < len1) {
            arr[index++] = arr1[ind1++];
        }
        while (ind2 < len2) {
            arr[index++] = arr2[ind2++];
        }

        delete[] arr1;
        delete[] arr2;
    }

    void ms(vector<int>& arr, int s, int e, int& reversePairsCount) {
        if (s >= e) {
            return;
        }
        int mid = s + (e - s) / 2;

        ms(arr, s, mid, reversePairsCount);
        ms(arr, mid + 1, e, reversePairsCount);
        mergesort(arr, s, e, reversePairsCount);
    }

    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        ms(nums, 0, nums.size() - 1, reversePairsCount);
        return reversePairsCount;
    }
};
