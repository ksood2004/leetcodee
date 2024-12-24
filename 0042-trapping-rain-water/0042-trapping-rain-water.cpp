class Solution {
public:
    int mah(vector<int>& heights){
    int n = heights.size();
    vector<int> prem;  // To store nearest smaller to left indices
    vector<int> neha;  // To store nearest smaller to right indices
    stack<int> karan;   // Stack for left smaller
    stack<int> aaryan; // Stack for right smaller

    // Code for nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!karan.empty() && karan.top() <= heights[i]) {
            karan.pop();
        }
        if (karan.empty()) {
            prem.push_back(-1);
        } else {
            prem.push_back(karan.top());
        }
        karan.push(heights[i]);
    }

    // Code for nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!aaryan.empty() && aaryan.top() <= heights[i]) {
            aaryan.pop();
        }
        if (aaryan.empty()) {
            neha.push_back(n); // Push `n` when no smaller element is found
        } else {
            neha.push_back(aaryan.top());
        }
        aaryan.push(heights[i]);
    }

    reverse(neha.begin(), neha.end()); 

    int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = neha[i] - prem[i] - 1;  
            int area = heights[i] * width;     
            maxArea = max(maxArea, area);     
        }

        return maxArea;
}

    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        vector<int> left(n), right(n);
//left to right side ka hai yeh
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }
//right to left side ka hai yeh
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) { // n-1 considered nhi krna isme
            right[i] = max(right[i + 1], height[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += max(0, min(left[i], right[i]) - height[i]);
        }

        return totalWater;
    
        
    }
};