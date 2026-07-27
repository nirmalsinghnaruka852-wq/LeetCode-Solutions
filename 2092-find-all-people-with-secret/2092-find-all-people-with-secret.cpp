using vi = vector<int>;
using vii = vector<vi>;
using vp = vector<pair<int, int>>;
using vvp = vector<vp>;
using p = pair<int, int>;

class Comparator {
public:
    bool operator()(const p& a, const p& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vvp adj(n);

        for (vi& edge : meetings) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adj[u].push_back({time, v});
            adj[v].push_back({time, u});
        }

        priority_queue<p, vector<p>, Comparator> pq;

        vector<int> knowTime(n, INT_MAX);

        knowTime[0] = 0;
        knowTime[firstPerson] = 0;

        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            p node = pq.top();
            pq.pop();

            int currentTime = node.first;
            int person = node.second;

            if (currentTime > knowTime[person])
                continue;

            for (p& edge : adj[person]) {
                int meetingTime = edge.first;
                int nextPerson = edge.second;

                if (meetingTime < currentTime)
                    continue;

                if (knowTime[nextPerson] <= meetingTime)
                    continue;

                knowTime[nextPerson] = meetingTime;
                pq.push({meetingTime, nextPerson});
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (knowTime[i] != INT_MAX)
                ans.push_back(i);
        }

        return ans;
    }
};