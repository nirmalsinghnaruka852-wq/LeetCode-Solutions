class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        unordered_map<int, int> values;

        int sum = 0;
        int ans = 0;

        values[0] = -1;

        for (int index = 0; index < n; index++) {
            nums[index] = nums[index] == 0 ? -1 : 1;
            
            sum += nums[index];
            prefix[index] = sum;

            if (values.count(sum)) {
                ans = max(ans, index - values[sum]);
            } else {
                values[sum] = index;
            }
        }

        return ans;
    }
};