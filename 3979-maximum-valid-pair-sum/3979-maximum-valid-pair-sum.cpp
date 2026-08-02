class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int best = nums[0];
        int ans = INT_MIN;

        for (int j = k; j < n; j++) {

            best = max(best, nums[j - k]);

            ans = max(ans, best + nums[j]);
        }

        return ans;
    }
};