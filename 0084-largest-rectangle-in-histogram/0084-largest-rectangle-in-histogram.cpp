class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
    vector<int> prem;  // To store nearest smaller to left indices
    vector<int> neha;  // To store nearest smaller to right indices
    stack<pair<int, int>> karan;   // Stack for left smaller
    stack<pair<int, int>> aaryan; // Stack for right smaller

    // Code for nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!karan.empty() && karan.top().first >= heights[i]) {
            karan.pop();
        }
        if (karan.empty()) {
            prem.push_back(-1);
        } else {
            prem.push_back(karan.top().second);
        }
        karan.push({heights[i], i});
    }

    // Code for nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!aaryan.empty() && aaryan.top().first >= heights[i]) {
            aaryan.pop();
        }
        if (aaryan.empty()) {
            neha.push_back(n); // Push `n` when no smaller element is found
        } else {
            neha.push_back(aaryan.top().second);
        }
        aaryan.push({heights[i], i});
    }

    reverse(neha.begin(), neha.end()); 

    // Calculate the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = neha[i] - prem[i] - 1;  // Width of the rectangle
        int area = heights[i] * width;         // Area = height * width
        maxArea = max(maxArea, area);      // Update maximum area
    }

    return maxArea;
        
    }
};