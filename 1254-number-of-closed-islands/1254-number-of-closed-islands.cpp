class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        for (auto dir : dirs) {
            int row = i + dir.first;
            int col = j + dir.second;
            if (row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size()  ||
                grid[row][col] == 1)
                continue;
            dfs(row, col, grid);
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if ((row == 0 || col == 0 || row == n - 1 || col == m - 1) &&
                    grid[row][col] == 0)
                    dfs(row, col, grid);
            }
        }
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 0) {
                    ans++;
                    dfs(row, col, grid);
                }
            }
        }
        return ans;
    }
};