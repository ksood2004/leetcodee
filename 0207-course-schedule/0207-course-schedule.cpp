class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (!dfs(neighbor, adj, vis, pathVis))
                    return false;
            } else if (pathVis[neighbor]) {
                return false; // cycle detected
            }
        }

        pathVis[node] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            int u = edge[1]; // prerequisite
            int v = edge[0]; // course
            adj[u].push_back(v); // edge: prerequisite -> course
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};
