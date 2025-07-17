class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(candidates, target, 0, comb, res);
        return res;
    }

private:
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }

        if (target < 0 || idx == candidates.size()) {
            return;
        }

        // Include current number
        comb.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, comb, res);  // stay on same idx for unbounded use
        comb.pop_back();

        // Exclude current number
        backtrack(candidates, target, idx + 1, comb, res);
    }
};
