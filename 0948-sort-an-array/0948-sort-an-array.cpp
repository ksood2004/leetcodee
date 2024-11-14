#include <vector>
using namespace std;

class Solution {
public:
    // Merge function to merge two sorted halves
    void mergesor(vector<int>& arr, int s, int e) {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        // Temporary arrays to store the two halves
        int *first = new int[len1];
        int *second = new int[len2];

        // Copy values into temp arrays
        int index = s;
        for (int i = 0; i < len1; i++) {
            first[i] = arr[index++];
        }

        index = mid + 1;
        for (int i = 0; i < len2; i++) {
            second[i] = arr[index++];
        }

        // Merge the two sorted halves back into the main array
        int ind1 = 0, ind2 = 0;
        index = s;

        while (ind1 < len1 && ind2 < len2) {
            if (first[ind1] <= second[ind2]) {
                arr[index++] = first[ind1++];
            } else {
                arr[index++] = second[ind2++];
            }
        }

        // Copy any remaining elements from first and second arrays
        while (ind1 < len1) {
            arr[index++] = first[ind1++];
        }
        while (ind2 < len2) {
            arr[index++] = second[ind2++];
        }

        // Free the allocated memory
        delete[] first;
        delete[] second;
    }

    // Merge sort function to divide the array
    void merge(vector<int>& arr, int s, int e) {
        if (s >= e) {
            return;
        }
        int mid = s + (e - s) / 2;

        // Recursively split the array into halves
        merge(arr, s, mid);
        merge(arr, mid + 1, e);

        // Merge the two sorted halves
        mergesor(arr, s, e);
    }

    // Function to sort the array
    vector<int> sortArray(vector<int>& nums) {
        merge(nums, 0, nums.size() - 1);
        return nums;
    }
};
