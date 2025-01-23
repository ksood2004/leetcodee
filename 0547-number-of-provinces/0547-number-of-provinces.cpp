class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true; // Mark the current node as visited
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited); // Recursively visit unvisited neighbors
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size(); // Number of nodes (provinces)
        vector<vector<int>> adj(v); // Adjacency list representation

        // Create adjacency list from adjacency matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(v, false); // Visited array to track visited nodes
        int provinces = 0;             // Count of connected components

        // Count connected components using DFS
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, adj, visited); // Perform DFS for each unvisited node
            }
        }

        return provinces; // Return the count of connected components
    }
};
