class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        // Count the frequency of each number
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Min-heap to store pairs (frequency, number)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Iterate through the frequency map
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
            minHeap.push({it->second, it->first}); // Push frequency and number
            if (minHeap.size() > k) {
                minHeap.pop(); // Maintain the size of the heap as k
            }
        }

        // Extract the top K elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second); // Get the number
            minHeap.pop();
        }

        return result; // Return the top K frequent elements
    }
};
