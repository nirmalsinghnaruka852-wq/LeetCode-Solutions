
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
 int n;
    int m;
    vvi dp;
    int VaildLongestPossibleSubsequence(int i, int j, string& t1, string& t2) {
        if (i >= n) {
            int sum = 0;

            for (int k = j; k < m; k++)
                sum += t2[k];

            return sum;
        }

        if (j >= m) {
            int sum = 0;

            for (int k = i; k < n; k++)
                sum += t1[k];

            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (t1[i] == t2[j]) {
            return dp[i][j] =
                       VaildLongestPossibleSubsequence(i + 1, j + 1, t1, t2);
        }

        return dp[i][j] = min(
                   t2[j] + VaildLongestPossibleSubsequence(i, j + 1, t1, t2),
                   t1[i] + VaildLongestPossibleSubsequence(i + 1, j, t1, t2));
    }
    int minimumDeleteSum(string s1, string s2) {
       n = s1.size();
        m = s2.size();
        dp.resize(n, vi(m, -1));
        return VaildLongestPossibleSubsequence(0, 0, s1, s2);
        
    }
};

