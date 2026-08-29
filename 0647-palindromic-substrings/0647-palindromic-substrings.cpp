using vb = vector<bool>;
using vvb = vector<vb>;

class Solution {
public:
    vvb dp;

    int countSubstrings(string s) {
        int n = s.size();

        dp.resize(n, vb(n, false));

        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {

                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};