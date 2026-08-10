class Solution {
public:
    vector<int> dp;

    int dfs(int currentIndex, int prev, vector<int>& nums) {
        if (currentIndex >= nums.size())
            return 0;

        if (dp[currentIndex] != -1)
            return dp[currentIndex];

        int i = currentIndex;
        int sum = 0;

        while (i < nums.size() && nums[currentIndex] == nums[i])
            sum += nums[i++];

        int notTake = dfs(i, prev, nums);

        while (i < nums.size() && nums[currentIndex] + 1 == nums[i])
            i++;

        int take = sum + dfs(i, prev, nums);

        return dp[currentIndex] = max(notTake, take);
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        dp.resize(nums.size(), -1);

        return dfs(0, 0, nums);
    }
};