using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int n;
    int m;
    vvi dp;
    int LCS(int i, int j, string& s1, string& s2) {
        if (i >= n || j >= m)
            return (i >= n) ? m - j : n - i;
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        if (s1[i] == s2[j])
            return  dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2);
        return dp[i][j] = 1 + min(LCS(i + 1, j, s1, s2), LCS(i, j + 1, s1, s2));
    }
    string shortestCommonSupersequence(string str1, string str2) {
         n = str1.size();
         m = str2.size();
        dp.resize(n +1, vi(m + 1 , INT_MAX));
        LCS(0, 0, str1, str2);
        int i = 0;
        int j = 0;
        string ans;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] <=  dp[i][j + 1]) {
                ans += str1[i];
                i++;
            } else {
                ans += str2[j];
                j++;
            }
        }
        while (i < n) {
            ans += str1[i++];
        }

        while (j < m) {
            ans += str2[j++];
        }

        return ans;
    }
};