using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

class Solution {
public:
    viii dp;

    // prevIndex, currentIndex, direction
    // direction:
    // 0 -> need smaller
    // 1 -> need bigger

    int dfs(int currentIndex, vector<int>& nums,
            int prevIndex, int direction) {

        if (currentIndex >= nums.size())
            return 0;

        if (dp[prevIndex][currentIndex][direction] != -1)
            return dp[prevIndex][currentIndex][direction];

        int Max = 0;

        if (direction == 0) {
            if (nums[currentIndex] < nums[prevIndex]) {
                Max = max(Max,
                    1 + dfs(currentIndex + 1, nums,
                            currentIndex, 1));
            }
        }
        else {
            if (nums[currentIndex] > nums[prevIndex]) {
                Max = max(Max,
                    1 + dfs(currentIndex + 1, nums,
                            currentIndex, 0));
            }
        }

        Max = max(Max,
            dfs(currentIndex + 1, nums,
                prevIndex, direction));

        dp[prevIndex][currentIndex][direction] = Max;

        return Max;
    }

    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        dp.assign(n, vii(n, vi(2, -1)));

        int smaller = dfs(1, nums, 0, 0);
        int bigger  = dfs(1, nums, 0, 1);

        return 1 + max(smaller, bigger);
    }
};