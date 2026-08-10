class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int index, int prevIndex, vector<int>& nums) {
        if (index == nums.size())
            return 0;

        if (dp[index][prevIndex + 1] != -1)
            return dp[index][prevIndex + 1];

        int skip = dfs(index + 1, prevIndex, nums);

        
        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + dfs(index + 1, index, nums);
        }

        return dp[index][prevIndex + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return dfs(0, -1, nums);
    }
};