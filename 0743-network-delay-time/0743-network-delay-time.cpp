class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> mp;

        for (auto &edge : times) {
            mp[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        q.push({0, k});

        while (!q.empty()) {

            auto node = q.top();
            q.pop();

            int currentDistance = node.first;
            int currentNode = node.second;

            if (currentDistance > dist[currentNode])
                continue;

            if (mp.count(currentNode)) {

                for (auto p : mp[currentNode]) {

                    int newDistance = currentDistance + p.second;

                    if (newDistance < dist[p.first]) {

                        dist[p.first] = newDistance;
                        q.push({newDistance, p.first});
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};