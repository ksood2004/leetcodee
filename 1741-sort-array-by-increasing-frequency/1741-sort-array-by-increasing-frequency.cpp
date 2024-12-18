#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Use a priority queue (max-heap) to order by frequency
        // and in case of ties, order by value in decreasing order.
        priority_queue<pair<int, int>> maxHeap;

        // Insert all elements into the max-heap
        for (auto& entry : freqMap) {
            // We negate the frequency to use the max-heap for sorting by frequency in ascending order
            maxHeap.push({-entry.second, entry.first}); // {neg_freq, value}
        }

        // Step 3: Rebuild the result array
        vector<int> result;
        
        // Pop elements from the heap and add them to the result array
        while (!maxHeap.empty()) {
            int freq = -maxHeap.top().first;  // Frequency (negated to get the original value)
            int value = maxHeap.top().second; // Value
            maxHeap.pop();
            
            // Add the current value `freq` times to the result array
            for (int i = 0; i < freq; ++i) {
                result.push_back(value);
            }
        }

        return result;
    }
};
