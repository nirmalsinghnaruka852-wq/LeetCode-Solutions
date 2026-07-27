using vvb = vector<vector<bool>>;
using vi = vector<int>;
using vp = vector<pair<int, int>>;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int n = 8;

        if (start == target)
            return true;

        vvb visited(n, vector<bool>(n, false));
        queue<vi> q;

        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        vp dirs = {
            {-2, -1}, {-2, 1}, {-1, -2}, {1, -2},
            {2, -1}, {2, 1}, {-1, 2}, {1, 2}
        };

        while (!q.empty()) {
            vi node = q.front();
            q.pop();

            for (pair<int, int>& dir : dirs) {
                int r = node[0] + dir.first;
                int c = node[1] + dir.second;
                int move = node[2] + 1;

                if (r < 0 || c < 0 || r >= n || c >= n || visited[r][c])
                    continue;

                if (r == target[0] && c == target[1])
                    return move % 2 == 0;

                visited[r][c] = true;
                q.push({r, c, move});
            }
        }

        return false;
    }
};