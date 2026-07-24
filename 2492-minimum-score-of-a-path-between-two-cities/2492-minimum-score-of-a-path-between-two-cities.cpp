class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {

        if (vis[node])
            return;

        vis[node] = true;

        for (auto& it : adj[node]) {
            ans = min(ans, it.first);
            dfs(it.second, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& e : roads) {
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }

        vector<bool> vis(n + 1, false);

        dfs(1, adj, vis);

        return ans;
    }
};