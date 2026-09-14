class Solution {
public:
    vector<vector<int>> dp;

    int solve(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

       
        int ans = 1 + solve(s, i + 1, j);
   
        for (int k = i +1 ; k <= j; k++) {
            if (s[i] == s[k]) {
                ans = min(ans,
                          solve(s, i + 1, k - 1) +
                          solve(s, k, j));
            }
        }

        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(s, 0, n - 1);
    }
};