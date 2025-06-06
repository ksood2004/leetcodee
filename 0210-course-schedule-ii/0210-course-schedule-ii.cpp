class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis, int node, vector<int>& topo) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                if (!dfs(adj, vis, pathvis, neighbour, topo)) {
                    return false;
                }
            } else if (pathvis[neighbour]) {
                return false; // cycle detected
            }
        }

        pathvis[node] = 0;
        topo.push_back(node); // topological order
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u); // v → u (u depends on v)
        }  

        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<int> topo;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(adj, vis, pathvis, i, topo)) {
                    return {}; // cycle found, ordering not possible
                }
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};
