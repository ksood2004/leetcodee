class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if (intervals.empty()) return {};

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        auto& last = result.back();

        // Step 2: Check for overlap
        if (intervals[i][0] <= last[1]) {
            // Merge by updating the end of the last interval
            last[1] = max(last[1], intervals[i][1]);
        } else {
            // No overlap, just add the current interval
            result.push_back(intervals[i]);
        }
    }

    return result;

        
    }
};