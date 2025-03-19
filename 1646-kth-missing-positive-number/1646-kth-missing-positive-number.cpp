#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        priority_queue<int, vector<int>, greater<int>> karan;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }

        int missingCount = 0, current = 1;
        while (missingCount < k) {
            if (mpp.find(current) == mpp.end()) {
                karan.push(current);
                missingCount++;
            }
            current++;
        }
        while (k > 1) {
            karan.pop();  
            k--;
        }

        return karan.top();  
    }
};
