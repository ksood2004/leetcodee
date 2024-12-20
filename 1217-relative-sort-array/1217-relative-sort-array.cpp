class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq; // To store frequency of elements in arr1
        vector<int> result; // To store the final sorted array
        vector<int> remaining; // To store elements not in arr2
 
        // Step 1: Count the frequency of elements in arr1
        for (int i=0;i<arr1.size();i++) {
            freq[arr1[i]]++;
        }

        // Step 2: Add elements from arr2 into the result in relative order
        for (int i=0;i<arr2.size();i++) {
            while (freq[arr2[i]] > 0) {
                result.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        // Step 3: Add remaining elements into the 'remaining' vector
        for (auto it=freq.begin(); it!=freq.end();it++) {
            int key=it->first;
            int value=it->second;
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
