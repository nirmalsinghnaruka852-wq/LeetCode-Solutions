class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        vector<pair<int, int>> dirs = {
            {0,1}, {1,0}, {-1,0}, {0,-1}
        };

        for (auto &src : sources) {
            int r = src[0];
            int c = src[1];
            int color = src[2];

            ans[r][c] = color;
            q.push({r, c});
        }

        while (!q.empty()) {

            int size = q.size();

            
            map<pair<int,int>, int> nextLevel;

            while (size--) {

                auto [r, c] = q.front();
                q.pop();

                for (auto &d : dirs) {

                    int nr = r + d.first;
                    int nc = c + d.second;

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;

                    
                    if (ans[nr][nc] != 0)
                        continue;

                    nextLevel[{nr, nc}] =
                        max(nextLevel[{nr, nc}], ans[r][c]);
                }
            }

            for (auto &it : nextLevel) {
                int r = it.first.first;
                int c = it.first.second;

                ans[r][c] = it.second;
                q.push({r, c});
            }
        }

        return ans;
    }
};