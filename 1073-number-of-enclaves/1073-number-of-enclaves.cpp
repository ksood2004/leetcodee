class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& adj) {
        if(i < 0 || j < 0 || i >= n || j >= m || adj[i][j] != 1)
            return;

        adj[i][j] = 2;

        dfs(i+1, j, n, m, adj);
        dfs(i-1, j, n, m, adj);
        dfs(i, j+1, n, m, adj);
        dfs(i, j-1, n, m, adj);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Run DFS for all boundary 1s
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1)
                dfs(i, 0, n, m, grid);
            if(grid[i][m - 1] == 1)
                dfs(i, m - 1, n, m, grid);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1)
                dfs(0, j, n, m, grid);
            if(grid[n - 1][j] == 1)
                dfs(n - 1, j, n, m, grid);
        }

        // Step 2: Count remaining 1s
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    cnt++;
            }
        }

        return cnt;
    }
};
