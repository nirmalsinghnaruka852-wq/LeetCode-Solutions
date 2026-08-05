using vi = vector<int>;
using vii = vector<vi>;
class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vii graph(n);
        vector<bool> visited(n, false);
        vector<int> Indgree(n, 0);
        for (vi& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            Indgree[v]++;
        }
        queue<int> q;
        q.push(k);
        visited[k] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nebhigor : graph[node]) {
                Indgree[nebhigor]--;
                if (visited[nebhigor])
                    continue;
                visited[nebhigor] = true;
                
                q.push(nebhigor);
            }
        }
        vi ans1;
        for (int index = 0; index < n; index++) {
            ans1.push_back(index);
        }
        vi ans;
        for (int index = 0; index < n; index++) {
            if (visited[index] && Indgree[index] > 0)
                return ans1;
            else if (!visited[index])
                ans.push_back(index);
        }
        return ans;
    }
};