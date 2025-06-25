class Solution {
public:
    int findPeakIndex(MountainArray &mountainArr, int n) {
        int s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    int binarySearch(MountainArray &mountainArr, int target, int start, int end, bool ascending) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            if (ascending) {
                if (val < target) start = mid + 1;
                else end = mid - 1;
            } else {
                if (val > target) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeakIndex(mountainArr, n);

        // Search in ascending part
        int idx = binarySearch(mountainArr, target, 0, peak, true);
        if (idx != -1) return idx;

        // Search in descending part
        return binarySearch(mountainArr, target, peak + 1, n - 1, false);
    }
};
