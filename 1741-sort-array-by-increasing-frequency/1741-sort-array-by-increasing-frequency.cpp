#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Build frequency map
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Convert the map to a vector of pairs (frequency, number)
        vector<pair<int, int>> freqVec;
        for (auto& entry : freqMap) {
            freqVec.push_back({entry.second, entry.first});
        }
        
        // Step 3: Sort the vector first by frequency (increasing), 
        // then by value (decreasing) in case of ties.
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;  // Sort by value in decreasing order if frequencies are equal
            }
            return a.first < b.first;  // Sort by frequency in increasing order
        });
        
        // Step 4: Rebuild the sorted array
        vector<int> result;
        for (auto& entry : freqVec) {
            result.insert(result.end(), entry.first, entry.second);  // Add `entry.first` copies of `entry.second`
        }
        
        return result;
    }
};
