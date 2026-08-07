using vi = vector<int>;
using vii = vector<vi>;
class Solution {
public:
    vii dp;
    int dfs(int index, int remaning, vi& coins) {
        if (remaning <= 0)
            return remaning == 0 ? 1 : 0;
        else if (index >= coins.size())
            return 0;
        else if (dp[index][remaning] != -1)
            return dp[index][remaning];
        int take = dfs(index, remaning - coins[index], coins);
        int notTake = dfs(index + 1, remaning, coins);
        return dp[index][remaning] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins);
    }
};