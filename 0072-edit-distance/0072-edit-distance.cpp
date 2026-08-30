using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int n, m;
    vvi dp;

    int TheMinumDistance(
        int i,
        int j,
        string& word1,
        string& word2
    ) {
        if (i >= n)
            return m - j;

        if (j >= m)
            return n - i;

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] =
                TheMinumDistance(i + 1, j + 1, word1, word2);
        }

        return dp[i][j] = 1 + min({
            TheMinumDistance(i + 1, j, word1, word2),     
            TheMinumDistance(i, j + 1, word1, word2),     
            TheMinumDistance(i + 1, j + 1, word1, word2)  
        });
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();

        dp.assign(n, vi(m, INT_MAX));

        return TheMinumDistance(0, 0, word1, word2);
    }
};