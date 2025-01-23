class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int originalColor = image[sr][sc];

        // If the starting pixel already has the target color, no changes are needed
        if (originalColor == color) {
            return image;
        }

        // Define directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Use a queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color; // Change the starting pixel to the new color

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check all 4 directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check if the new position is valid and has the original color
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && image[nx][ny] == originalColor) {
                    image[nx][ny] = color; // Change color
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};
