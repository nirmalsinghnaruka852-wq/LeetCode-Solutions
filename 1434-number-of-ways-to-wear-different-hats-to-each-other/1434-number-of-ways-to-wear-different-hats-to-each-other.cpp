class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n;
    vector<vector<int>> dp;
    vector<vector<int>> hatToPeople;

    int solve(int hat, int mask) {
        if (mask == (1 << n) - 1)
            return 1;
        if (hat > 40)
            return 0;

        if (dp[hat][mask] != -1)
            return dp[hat][mask];

        long long ans = 0;
        ans = solve(hat + 1, mask);

        for (int person : hatToPeople[hat]) {

           
            if (mask & (1 << person))
                continue;

            int newMask = mask | (1 << person);

            ans += solve(hat + 1, newMask);
            ans %= MOD;
        }

        return dp[hat][mask] = ans;
    }

    int numberWays(vector<vector<int>>& hats) {

        n = hats.size();

        hatToPeople.resize(41);

        for (int person = 0; person < n; person++) {
            for (int hat : hats[person]) {
                hatToPeople[hat].push_back(person);
            }
        }

        dp.assign(41, vector<int>(1 << n, -1));

        return solve(1, 0);
    }
};