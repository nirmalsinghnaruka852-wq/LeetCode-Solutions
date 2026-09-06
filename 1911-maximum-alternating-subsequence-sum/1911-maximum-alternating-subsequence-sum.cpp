using vi = vector<long long>;
using vvi = vector<vi>;

class Solution {
public:
    vvi dp;
    int n;
    vi arr;

    long long solve(int i = 0, int flag = 0) {
        if (i >= n) return 0;

        if (dp[i][flag] != -1)
            return dp[i][flag];

        if (flag == 0) {
            // Take nums[i] as positive
            long long take = arr[i] + solve(i + 1, 1);

            // Don't take
            long long do_nothing = solve(i + 1, flag);

            return dp[i][flag] = max(take, do_nothing);
        }
        else {
            // Take nums[i] as negative
            long long take = -arr[i] + solve(i + 1, 0);

            // Don't take
            long long do_nothing = solve(i + 1, flag);

            return dp[i][flag] = max(take, do_nothing);
        }
    }

    long long maxAlternatingSum(vector<int>& nums) {
        arr.assign(nums.begin(), nums.end());
        n = nums.size();

        dp.assign(n, vi(2, -1));

        return solve();
    }
};