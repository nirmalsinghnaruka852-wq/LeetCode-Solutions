using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
class Solution {
public:
    int n;
    vvb dp;

    string longestPalindrome(string s) {
        n = s.size();
        dp.resize(n, vb(n, false));
        pii startingLocation = {-1, -1};
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int MaxOne = -1;
        for (int length = 0; length < n; length++) {
            for (int i = 0; i < n; i++) {
                int j = i + length;
                if (j >= n)
                    continue;
                if (length == 0) {
                    dp[i][j] = true;
                } else if (length == 1 ) {
                    dp[i][j] = s[i] == s[j];
                } else
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j]) {

                    int differnet = abs(i - j);

                    if (differnet > MaxOne) {
                        MaxOne = differnet;
                        startingLocation = make_pair(i, j);
                    }
                }
            }
        }
        if (startingLocation.first == -1)
            return "";
        cout << MaxOne;
        return s.substr(startingLocation.first,
                        startingLocation.second - startingLocation.first + 1);
    }
};