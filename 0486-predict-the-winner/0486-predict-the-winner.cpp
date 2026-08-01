class Solution {
public:
    vector<vector<int>> dp;
    int Minmax(int left, int right, vector<int>& nums) {
        if (left == right)
            return nums[left];
        else if (dp[left][right] != -1)
            return dp[left][right];
        int LeftPick = nums[left] - Minmax(left + 1, right, nums);
        int rightPick = nums[right] - Minmax(left, right - 1, nums);
        return dp[left][right] = max(LeftPick, rightPick);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        return Minmax(0 ,  n-1 , nums ) >= 0 ;
    }
};