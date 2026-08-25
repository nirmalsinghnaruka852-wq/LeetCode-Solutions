using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;

class Solution {
public:
    vvi dp;

    vpii dirs = {{-1, 1}, {0, 1}, {1, 1}};

    bool checkboundry(int row, int col, int n, int m) {
        return row < 0 || col < 0 || row >= n || col >= m;
    }

    int dfs(int row, int col, int n, int m, vvi& matrix) {
        if (dp[row][col] != INT_MIN)
            return dp[row][col];

        int MaxOne = 0;

        for (pii& dir : dirs) {
            int r = row + dir.first;
            int c = col + dir.second;

            if (checkboundry(r, c, n, m) ||
                matrix[r][c] <= matrix[row][col])
                continue;

            MaxOne = max(MaxOne, 1 + dfs(r, c, n, m, matrix));
        }

        return dp[row][col] = MaxOne;
    }

    int maxMoves(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        dp.resize(n, vector<int>(m, INT_MIN));

        int maxOne = 0;

        for (int row = 0; row < n; row++) {
            maxOne = max(maxOne, dfs(row, 0, n, m, matrix));
        }

        return maxOne;
    }
};