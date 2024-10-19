class Solution {
public:
void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void reverseRows(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Function to reverse each row

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);

    // Step 2: Reverse each row
    reverseRows(matrix);
    }
};