class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> s;
        unordered_map<int, int> nge;
        vector<int> karan;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                nge[nums2[i]] = -1;
            } else {
                nge[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for (int num : nums1) {
            karan.push_back(nge[num]);
        }

        return karan;
    }
};
