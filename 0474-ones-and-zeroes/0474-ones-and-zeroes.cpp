using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

class Solution {
public:
    vvvi dp;
    int generateSubSet(int currentIndex, int req0, int req1, vs& strs) {

        if (currentIndex >= strs.size())
            return 0;

        if (req0 == 0 && req1 == 0)
            return 0;

        if (dp[currentIndex][req0][req1] != -1)
            return dp[currentIndex][req0][req1];

        int count0 = 0;
        int count1 = 0;

        for (char ch : strs[currentIndex]) {
            if (ch == '1')
                count1++;
            else
                count0++;
        }

        int not_take = generateSubSet(currentIndex + 1, req0, req1, strs);

        if (count1 > req1 || count0 > req0)
            return dp[currentIndex][req0][req1] = not_take;

        int take = 1 + generateSubSet(currentIndex + 1, req0 - count0,
                                      req1 - count1, strs);

        return dp[currentIndex][req0][req1] = max(take, not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        dp.resize(size, vvi(m + 1, vi(n + 1, -1)));
        return generateSubSet(0, m, n, strs);
    }
};