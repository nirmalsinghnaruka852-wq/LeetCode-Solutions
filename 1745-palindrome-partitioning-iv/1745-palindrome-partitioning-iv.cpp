using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int n;
    vvi pal;
    vvi dp;

    bool dfs(int index, int require, string& s) {

        // No more cuts.
        // Remaining substring must be a palindrome.
        if (require == 0) {
            return pal[index][n - 1];
        }

        if (dp[index][require] != -1)
            return dp[index][require];

        for (int j = index; j < n; j++) {

            if (pal[index][j]) {
                if (j == n - 1)
                    continue;

                if (dfs(j + 1, require - 1, s))
                    return dp[index][require] = 1;
            }
        }

        return dp[index][require] = 0;
    }

    bool checkPartitioning(string s) {

        n = s.size();

        pal.resize(n, vi(n, false));
        dp.resize(n, vi(3, -1));

      
        for (int length = 0; length < n; length++) {

            for (int i = 0; i < n; i++) {

                int j = i + length;

                if (j >= n)
                    break;

                if (length == 0)
                    pal[i][j] = true;

                else if (length == 1)
                    pal[i][j] = (s[i] == s[j]);

                else
                    pal[i][j] =
                        (s[i] == s[j]) &&
                        pal[i + 1][j - 1];
            }
        }

        return dfs(0, 2, s);
    }
};