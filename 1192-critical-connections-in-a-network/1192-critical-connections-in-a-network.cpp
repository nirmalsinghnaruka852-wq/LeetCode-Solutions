class Solution {
public:
    vector<vector<int>> bridges;
    vector<int> tin, low;
    vector<bool> visited;
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        visited[node] = true;
        tin[node] = low[node] = timer++;

        for (int neighbour : adj[node]) {

            // Ignore the edge we came from
            if (neighbour == parent)
                continue;

            if (!visited[neighbour]) {

                dfs(neighbour, node, adj);

                // Update low value
                low[node] = min(low[node], low[neighbour]);

                // Bridge Condition
                if (low[neighbour] > tin[node]) {
                    bridges.push_back({node, neighbour});
                }
            }
            else {
                // Back Edge
                low[node] = min(low[node], tin[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.resize(n);
        low.resize(n);
        visited.assign(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, -1, adj);
        }

        return bridges;
    }
};