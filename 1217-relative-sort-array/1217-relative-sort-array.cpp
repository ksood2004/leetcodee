class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq; // To store frequency of elements in arr1
        vector<int> result; // To store the final sorted array
        vector<int> remaining; // To store elements not in arr2

        // Step 1: Count the frequency of elements in arr1
        for (int num : arr1) {
            freq[num]++;
        }

        // Step 2: Add elements from arr2 into the result in relative order
        for (int num : arr2) {
            while (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        // Step 3: Add remaining elements into the 'remaining' vector
        for (auto& [key, value] : freq) {
            while (value > 0) {
                remaining.push_back(key);
                value--;
            }
        }

        // Step 4: Sort the remaining elements
        sort(remaining.begin(), remaining.end());

        // Step 5: Combine result and remaining elements
        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};
