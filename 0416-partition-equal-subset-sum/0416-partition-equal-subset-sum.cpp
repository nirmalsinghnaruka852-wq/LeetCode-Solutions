class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(int curr, int rem, vector<int>& nums) {
        if (rem == 0) return true;
        if (rem < 0) return false;
        if (curr == nums.size()) return false;

        if (dp[curr][rem] != -1)
            return dp[curr][rem];

        bool take = dfs(curr + 1, rem - nums[curr], nums);
        bool notTake = dfs(curr + 1, rem, nums);

        return dp[curr][rem] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int ele : nums)
            total += ele;

        if (total % 2 != 0)
            return false;

        int half = total / 2;

        dp.resize(nums.size(), vector<int>(half + 1, -1));

        return dfs(0, half, nums);
    }
};