class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(int row, int col, int m, int n, int move) {
        if (row < 0 || col < 0 || row >= m || col >= n)
            return 1;
        if (move == 0)
            return 0;
        if (dp[row][col][move] != -1)
            return dp[row][col][move];
        int total = 0;
        for (auto dir : dirs) {
            int r = row + dir.first;
            int c = col + dir.second;
            total = (total + dfs(r, c, m, n, move - 1)) % MOD;
        }
        return dp[row][col][move] = total;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, m, n, maxMove);
    }
};