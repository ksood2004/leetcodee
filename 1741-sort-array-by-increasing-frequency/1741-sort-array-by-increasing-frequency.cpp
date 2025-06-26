class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Min heap with tie-breaker: bigger number first if frequency same
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& it : freq) {
            pq.push({it.second, -it.first});  // store -num for tie-breaking
        }

        vector<int> result;
        while (!pq.empty()) {
            int count = pq.top().first;
            int num = -pq.top().second;  // restore original number
            pq.pop();
            for (int i = 0; i < count; i++) {
                result.push_back(num);
            }
        }

        return result;
    }
};
